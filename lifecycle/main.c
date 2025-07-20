#include "lifecycle.h"

int main() {
    LifeState state = {0};  // 初始化所有状态为0
    int choice = 0;

    while (1) {
        // 显示当前时间
        time_t now = time(NULL);
        printf("\n当前时间: %s", ctime(&now));

        // 生成随机选择
        choice = win_time_rand(1, 6);
        printf("系统选择: %d\n", choice);

        // 显示活动菜单
        print_menu();
        printf("%d\n", choice);  // 显示自动选择结果
        Sleep(1000);  // 1秒延迟

        // 根据选择执行对应操作
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
                    printf("无效选择! ");
                }
                continue;
        }

        // 更新基础生命指标
        life(&state);
        maintain(&state);

        // 打印当前状态
        print_state(&state);
    }

    return 0;
}