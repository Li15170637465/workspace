// 1. ��һ������,���ӵ�һ��������е�һ��,�����һ�����Ժ�ÿ����Ӷ������е�һ��,Ȼ���ٶ��һ����������ʮ��ʱ,���ٳ�ʱ��ע�⣺��ʱ��û�ԣ�,����ֻ��1�������ˡ�����������ٸ����� �ݹ�
// #include <stdio.h>

// int peach(int day) {
//     if (day == 10)  
//         return 1;
//     else
//         return (peach(day + 1) + 1) * 2; // ���ݺ�һ������������㵱���������
// }

// int main() {
//     int total = peach(1); // �����1���֮ǰ����������
//     printf("�������������Ϊ: %d\n", total);
//     return 0;
// }

// 2. �������
// �������ݹ����������������Ԫ��֮�͡�
// // ʾ������������ {1, 2, 3, 4},��� 100.
// #include <stdio.h>

// // �ݹ��������Ԫ��֮��
// int arraySum(int arr[], int start, int end) {
//     if (start > end) {  // �ݹ���ֹ����������������Ԫ��
//         return 0;
//     }
//     // �ݹ�ֽ⣺��ǰԪ�� + ʣ��Ԫ��֮��
//     return arr[start] + arraySum(arr, start + 1, end);
// }

// int main() {
//     int arr[] = {1, 2, 3, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);  // �������鳤��
    
//     int total = arraySum(arr, 0, n - 1);  // ������0��ʼ���
    
//     printf("����Ԫ��֮��: %d\n", total);  // ������
//     return 0;
// }
 


// 3 ���庯��,ʵ�ֽ�������������ֵ�� ����ԭ�� void exchange(int *, int *)
