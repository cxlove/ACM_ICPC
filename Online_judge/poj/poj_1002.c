#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', 
                '5', '5', '5', '6', '6', '6', '7', '7', '7', 
                '7', '8', '8', '8', '9', '9', '9', '9'};//按键映射表

char phone[100000][9];    //全部电话号码

int n;                    //电话号码的数量

char number[80];        //一个未经处理的电话号码


int main(void)
{
    int loop;                    //循环变量

    int phone_i=0, phone_j=0;    //phone数组的下标

    int tag = 0;                //重复标志，0没有处于一个重复，1有重复

    int count = 1;                //重复次数


    scanf("%d", &n);

    for(phone_i=0; phone_i<n; phone_i++){//格式化所有输入数据为111-1111的形式

        scanf("%s", number);
        for(loop=0; number[loop]!='\0'; loop++){//检查每一个字符

            if(phone_j == 3){//第四个字符必须是'-'

                phone[phone_i][phone_j] = '-';
                phone_j++;
            }
            if(number[loop]>='0' && number[loop]<='9'){//当前字符是数字

                phone[phone_i][phone_j] = number[loop];
            }
            else if(number[loop]>='A' && number[loop]<='Z'){//当前字符是大写字母

                phone[phone_i][phone_j] = map[number[loop]-'A'];
            }
            else if(number[loop] == '-'){//忽略'-'

                continue;
            }
            phone_j++;
        }
        phone_j = 0;
    }
    
    //排序全部电话号码

    qsort(phone, n, 9, strcmp);

    for(loop=1; loop<n; loop++){//检查重复次数，输出结果

        if(strcmp(phone[loop], phone[loop-1]) == 0){
            tag = 1;
            count++;
        }
        else{//没有重复

            if(count > 1){
                printf("%s %d\n", phone[loop-1], count);
            }
            count = 1;
        }
    }
    if(count > 1){//查看最后一条记录是否有重复

        printf("%s %d\n", phone[loop-1], count);
    }
    if(!tag) 
        printf("No duplicates.\n");
    return 0;
}
