#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transmission(int tf, int *tt) {
int prev = 0;
    for (int i = 1; i <= tf; i++) {
if(prev!=i){
        printf("Sending Frame %d ...\n", i);
}
        (*tt)++;

        // Randomly decide if ACK is received or not
        int ack = rand() % 2; // 0 = lost, 1 = received

        if (ack) {
            printf("Acknowledgement for Frame %d received.\n\n", i);
        } else {
            printf("Timeout!! Frame %d not acknowledged.\n", i);
            printf("Retransmitting Frame %d ...\n", i);
            (*tt)++;
	i--;
prev = i+1;
        }
    }
}

int main() {
    int tf, tt = 0;
    printf("Enter the Total number of frames: ");
    scanf("%d", &tf);


    transmission(tf, &tt);

    printf("Total number of transmissions (including retransmissions): %d\n", tt);
    return 0;
}
