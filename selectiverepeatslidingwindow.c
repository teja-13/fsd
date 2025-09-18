#include<stdio.h>

#include<stdlib.h>

#define ll int

void transmission(ll i, ll N, ll tf, ll *tt) {
  while (i <= tf) {
    int z = 0;
    for (int k = i; k < i + N && k <= tf; k++) {
      //cout << "Sending Frame " << k << "..." << endl;
      printf("Sending frame %d ...\n",k);
      (*tt)++;
    }
    for (int k = i; k < i + N && k <= tf; k++) {
      int f = rand() % 2;
      if (!f) {
        //cout << "Acknowledgment for Frame " << k << "..." << endl;
        printf("Acknowledgement for Frame %d ...\n",k);
        z++;
      } else {
        //cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
        printf("Timeout!! Frame Number : %d Not Recieved\n",k);
        //cout << "Retransmitting Window..." << endl;
        printf("Retransmitting Frame %d...\n",k--);
        (*tt)++;
      }
    }
    printf("\n");
    i = i + z;
  }
}

int main() {
  int tf, N, tt = 0,i=1;
  //srand(time(NULL));
  //cout << "Enter the Total number of frames : ";
  printf("Enter the Total number of frames : ");
  //cin >> tf;
  scanf("%d",&tf);
  //cout << "Enter the Window Size : ";
  printf("Enter the Window Size : ");
  //cin >> N;
  scanf("%d",&N);
  transmission(i,N,tf,&tt);
  //cout << "Total number of frames which were sent and resent are : " << tt <<
  printf("Total number of frames which were sent and resent are : %d",tt);
    //endl;
  return 0;
}
