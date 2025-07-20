#include "lifecycle.h"

int main() {
    LifeState state = {0};  // ��ʼ������״̬Ϊ0
    int choice = 0;

    while (1) {
        // ��ʾ��ǰʱ��
        time_t now = time(NULL);
        printf("\n��ǰʱ��: %s", ctime(&now));

        // �������ѡ��
        choice = win_time_rand(1, 6);
        printf("ϵͳѡ��: %d\n", choice);

        // ��ʾ��˵�
        print_menu();
        printf("%d\n", choice);  // ��ʾ�Զ�ѡ����
        Sleep(1000);  // 1���ӳ�

        // ����ѡ��ִ�ж�Ӧ����
        switch (choice) {
            case 1: sleep(&state); break;
            case 2: eat(&state); break;
            case 3: breath(&state); break;
            case 4: drink(&state); break;
            case 5: excretion(&state); break;
            case 6: warm(&state); break;
            default:
                while (choice < 1 || choice > 6) {
                    print_menu();
                    scanf("%d", &choice);
                    if (choice >= 1 && choice <= 6) break;
                    printf("��Чѡ��! ");
                }
                continue;
        }

        // ���»�������ָ��
        life(&state);
        maintain(&state);

        // ��ӡ��ǰ״̬
        print_state(&state);
    }

    return 0;
}