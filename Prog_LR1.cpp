#include <iostream>
#include <vector>
using namespace std;

struct Student {
    char surname[20];
    char name[20];
    char patronymic[20];
    int group;
    vector<int> scor;
    float avr_scor;
};

struct Group {
    vector<Student> st;
    int group = 0;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int i;

    const int grops = 3;
    const int students = 12;
    
    Student st[students] =
    {
        "Иванов",       "Василий",      "Иванович",         1, {86, 74, 95},  0,
        "Смирнов",      "Александр",    "Павлович",         3, {51, 89, 40}, 0,
        "Кузнецов",     "Даниил",       "Игоревич",         2, {95, 25, 15}, 0,
        "Попова",       "Мария",        "Александровна",    1, {51, 74, 61}, 0,
        "Васильева",    "Анна",         "Дмитриевна",       2, {66, 54, 17}, 0,
        "Петров",       "Алексей",      "Федорович",        3, {34, 43, 88}, 0,
        "Соколов",      "Дмитрий",      "Олегович",         1, {86, 74, 95}, 0,
        "Михайлов",     "Артем",        "Денисович",        2, {20, 35, 22}, 0,
        "Новикова",     "Елена",        "Юрьевна",          1, {29, 47, 62}, 0,
        "Фёдоров",      "Илья",         "Николаевич",       3, {57, 94, 91}, 0,
        "Морозов",      "Николай",      "Семенович",        3, {49, 37, 49}, 0,
        "Волкова",      "Елизавета",    "Романова",         2, {36, 79, 73}, 0,
    };
   

    Group gr[grops];

    for (i = 0; i < sizeof(st) / sizeof(*st); i++) {
        float sum = 0;
        int size = st[i].scor.size();
        for (int j = 0; j < size;j++) {
            sum += st[i].scor[j];
        }
        st[i].avr_scor = sum/size;
        gr[st[i].group - 1].st.push_back(st[i]);
        gr[st[i].group - 1].group = st[i].group;
    }
    int max_ind = 0;
    for (i = 0; i < sizeof(gr) / sizeof(*gr); i++) {
        int size = gr[i].st.size();
        printf("\n");
        for (int m = 0; m < size; m++) {
            float max = 0;
            for (int n = 0; n < size; n++) {
                if (gr[i].st[n].avr_scor > max)
                {
                    max = gr[i].st[n].avr_scor;
                    max_ind = n;
                }
            }
            printf("Група %i, %s %s %s,\t ср.балл: %1.0f \n", gr[i].group, gr[i].st[max_ind].surname, gr[i].st[max_ind].name, gr[i].st[max_ind].patronymic,gr[i].st[max_ind].avr_scor);
            gr[i].st[max_ind].avr_scor = 0;
        }
    }
}