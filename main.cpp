//九度书 第二章 例2.13 二分查找 先排序 然后base top mid
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct student
{
    char no[100];//学号 用来排序 没重复
    char name[100];
    int age;
    char sex[2];

    bool operator < (const struct student & A) const{
     return strcmp(no,A.no) < 0;
    }

}student[1000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i = 0;i < n;i++)
        {
            scanf("%s %s %d %s",student[i].no,student[i].name,&student[i].age,student[i].sex);
        }
        char tar[100];
        int m;
        scanf("%d",&m);
        for(i = 0;i < m;i ++){
        scanf("%s",tar);
        sort(student,student + n);
        int base = 0;
        int top = n;
        int mid;
        bool flag = false;
        //下面开始二分查找
        while(base <= top)
        {
            mid = (top + base) / 2;
            if(strcmp(student[mid].no,tar) == 0)
            {
                printf("%s %s %d %s\n",student[mid].no,student[mid].name,student[mid].age,student[mid].sex);
                flag = true;
                break;
            }
            else if(strcmp(student[mid].no,tar) > 0) top = mid - 1;
            else base = mid + 1;
        }
        if(flag == false) printf("NO ANSWER\n");
        }
    }
    return 0;
}
