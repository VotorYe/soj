#include<stdlib.h>
#include<stdio.h>

typedef enum { false, true } bool;

struct board
{
    int x;
    int y;
    int pre;
    int op;
};

int extend_queue(struct board* queue, int m, int n,
          int rp, int fp, int op) {
    bool exit_ = false;
    int i;
    for (i = 1; i <= rp; ++i)
    {
        if (m == queue[i].x
            && n == queue[i].y) {
            exit_ = true;
            break;
        }
    }
    
    if (exit_ == false) {
        rp++;
        queue[rp].x = m;
        queue[rp].y = n;
        queue[rp].pre = fp;
        queue[rp].op = op;
    }
    return rp;
}

void print_op(struct board* queue, int rp) {
    int count = 0;
    int i = rp;
    int output[10];
    char op[3] = {'A', 'B', 'C'};
    while (i != 1) {
        output[count] = queue[i].op;
        i = queue[i].pre;
        count++;
    }
    printf("%d ", count);
    for (i = count - 1; i >= 0; --i)
    {
        printf("%c", op[output[i]]);
    }
    printf("\n");
}

int main() {
    int N;
    struct board beginState;
    struct board targetState;

    beginState.x = 1234;
    beginState.y = 8765;
    beginState.pre = 0;

    while (scanf("%d", &N) && N != -1 && N <= 10) {
        bool flag = false;
        int count = 0;
        int fp = 1, rp = 1;
        int m, n;
        int x0, x1, x2, x3, y0, y1, y2, y3;
        struct board queue[100000];

        queue[1] = beginState;

        scanf("%d %d %d %d %d %d %d %d", &x0, &x1, &x2, &x3, &y0, &y1, &y2, &y3);
        targetState.x = x0*1000 + x1*100 + x2 * 10 + x3;
        targetState.y = y0*1000 + y1*100 + y2 * 10 + y3;
        if (targetState.x == beginState.x && targetState.y == beginState.y) {
            printf("0\n");
            continue;
        }
        while (count < N && fp <= rp && flag == false) {
            count++;
            
            /* OpA */
            m = queue[fp].y;
            n = queue[fp].x;
            rp = extend_queue(queue, m, n, rp, fp,0);
            if (m == targetState.x && n == targetState.y) {
                flag = true;
                break;
            }

            /* OpB */
            m = (queue[fp].x % 10) * 1000 + (queue[fp].x / 10);
            n = (queue[fp].y % 10) * 1000 + (queue[fp].y / 10);
            rp = extend_queue(queue, m, n, rp, fp,1);
            if (m == targetState.x && n == targetState.y) {
                flag = true;
                break;
            }

            /* OpC */
            x0 = queue[fp].x / 1000;
            x1 = (queue[fp].x % 1000) / 100 ;
            x2 = (queue[fp].x % 100) / 10;
            x3 = (queue[fp].x % 10);

            y0 = queue[fp].y / 1000;
            y1 = (queue[fp].y % 1000) / 100 ;
            y2 = (queue[fp].y % 100) / 10;
            y3 = (queue[fp].y % 10);

            m = x0*1000 + y1*100 + x1*10 + x3;
            n = y0*1000 + y2*100 + x2*10 + y3;
            rp = extend_queue(queue, m, n, rp, fp,2);
            if (m == targetState.x && n == targetState.y) {
                flag = true;
                break;
            }

            fp++;
        }
        if (flag == true) {
            print_op(queue, rp);
            printf("%d\n", rp);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}