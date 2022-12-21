/* add.c
 * a simple C program
 */

int x, y, z, u, v = 0;

void printf();
 
int main(int argc, char *argv[])
{
    int i, sum = x;
    double f = 1.5 + 2;
    char* c = "\x41";
    for( i = 1; i <= 20; i++ ) {
        int j;
        sum += i;
    } /*-for-*/
    switch(sum){
        case 0:
            sum++;
            break;
        case 1:
            sum = 0;
            break;
        default:
            sum = sizeof(int);
            break;
    }
    
    return 0;
}
