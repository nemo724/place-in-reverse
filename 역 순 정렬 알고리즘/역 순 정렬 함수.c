#include <stdio.h>


int main(void)
{int arr[7] = { 1,2,3,4,5,6,7 };
int reverse_min = 0;//역으로 뒤집을 범위의 가장 왼쪽 번호
int reverse_max = 0;//역으로 뒤집을 범위의 가장 오른쪽 번호
int temporary_save = 0;//위의 둘 자리를 바꾸기 전 max 위치에 해당하는 값을 저장하는 변수
int real_index_min = reverse_min - 1;//배열 내에서 역으로 뒤집을 범위의 가장 왼쪽 번호(reverse_min)의 실제 번호
int real_index_max = reverse_max - 1;//배열 내에서 역으로 뒤집을 범위의 가장 오른쪽 번호(reverse_max)의 실제 번호
int element_count = (reverse_max - reverse_min) + 1;//역순 할 구간 내 원소의 갯수를 알 수 있다
int try_count = 0;

while (1)
{printf("역순을 할 구간의 시작점과 끝점을 입력해 주세요: ");
scanf_s("%d%d", &reverse_min, &reverse_max);
if (reverse_min<0) { printf("1부터 시작 할 수 있습니다\n"); continue; }//시작점이 음수면 진행 불가
else if (reverse_max < reverse_min) { printf("시작점은 끝점보다 클 수 없습니다\n"); continue; }//시작점 끝나는 점보다 크면 진행 불가
else if (reverse_min > 7 || reverse_max > 7)//둘 다 또는 끝나는 점이 7을 벗어날시 
{printf("범위를 넘어 가는 값은 자동으로 7번째로 설정됩니다\n");//벗어난 값들은 자동으로 7로 설정 
if (reverse_max > 7) { reverse_max = 7; break; }
if (reverse_min > 7) { reverse_min = 7; break; }
}
else if (reverse_max >= reverse_min) { break; }//정상적인 값들은 여기서 진행되게 함
}

real_index_min = reverse_min - 1;//실제 배열 내 시작점 인덱스를 찾음
real_index_max = reverse_max - 1;//실제 배열 내 끝점 인덱스를 찾음
element_count = (reverse_max - reverse_min) + 1;//구간 내 원소의 갯수를 계산

if (element_count % 2 == 0) { try_count = element_count / 2; }//구간 내 원소의 갯수가 짝수 그 수의 그대로 절반 만큼 반복하게 함
else if (element_count % 2 == 1) { try_count = (element_count / 2) + 1; }//구간 내 원소의 갯수가 홀수면 +1하여 가운데 수는 자기 자신끼리 바꾸게 함

for (int i = 0; i < try_count; i++)
{temporary_save = *((arr+real_index_max)-i);//일단 교환 전 끝점-i값을 임시적으로 저장
*((arr+real_index_max) - i) = *((arr+real_index_min)+i);//끝 점에 해당하는 원소값-i를 시작 점에 해당하는 원소값+i로 초기화,
*((arr+real_index_min) + i) = temporary_save;//시작 점에 해당하는 원소값+i은 초기화 전 끝점-i값으로 초기화
}//참고로 배열 연산은 *((arr+real_index_max)-i)==arr[real_index_max-i]와 같다

//바뀐 결과 값 출력
printf("바뀐 배열의 결과는:");
for (int i = 0; i < 7; i++)
{printf("%d ", arr[i]); }



}