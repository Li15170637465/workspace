#include "lifecycle.h"

// ����Windows�����µ������
int win_time_rand(int min, int max) {
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    srand((unsigned int)(counter.QuadPart & 0xFFFFFFFF));
    return min + rand() % (max - min + 1);
}

// ������������
void life(LifeState* state) {
    if (state) state->cycleTimes++;
}

// ����״̬ά��
void maintain(LifeState* state) {
    if (state) state->healthStatus++;
}

// ��ʳ��Ϊ
void eat(LifeState* state) {
    if (state) state->foodEnergy++;
}

// ˯����Ϊ
void sleep(LifeState* state) {
    if (state) state->bedTime++;
}

// ������Ϊ
void breath(LifeState* state) {
    if (state) state->airQuality++;
}

// ��ˮ��Ϊ
void drink(LifeState* state) {
    if (state) state->waterVolume++;
}

// ��й��Ϊ
void excretion(LifeState* state) {
    if (state) state->toiletPlace++;
}

// ��ů��Ϊ
void warm(LifeState* state) {
    if (state) state->clothingEnvironment++;
}

// ��ӡ��ǰ״̬
void print_state(const LifeState* state) {
    if (!state) return;
    
    printf("\n=== ��ǰ״̬ ===\n");
    printf("�������ڼ���: %d\n", state->cycleTimes);
    printf("����״̬: %d\n", state->healthStatus);
    printf("��ʳ����: %d\n", state->foodEnergy);
    printf("˯��ʱ��: %d\n", state->bedTime);
    printf("��������: %d\n", state->airQuality);
    printf("��ˮ��: %d\n", state->waterVolume);
    printf("����״��: %d\n", state->toiletPlace);
    printf("��ůָ��: %d\n\n", state->clothingEnvironment);
}

// ��ӡ�˵�ѡ��
void print_menu(void) {
    printf("\n���ջѡ��:\n");
    printf("1. ˯��\n");
    printf("2. ��ʳ\n");
    printf("3. ����\n");
    printf("4. ��ˮ\n");
    printf("5. ��й\n");
    printf("6. ��ů\n");
    printf(">>> ��ѡ��(1-6): ");
}