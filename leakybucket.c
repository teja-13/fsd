#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_PACKETS 10

int get_random(int max_value) {
    int result = (rand() % 10) % max_value;
    return result == 0 ? 1 : result;
}

int main() {
    int packet_size[NUM_PACKETS];
    int i, clock_tick, bucket_size, output_rate;
    int remaining_data = 0, transmission_time, transmitted;

    for (i = 0; i < NUM_PACKETS; ++i)
        packet_size[i] = get_random(6) * 10;

    for (i = 0; i < NUM_PACKETS; ++i)
        printf("\nPacket[%d]: %d bytes", i + 1, packet_size[i]);

    printf("\n\nEnter the Output Rate (bytes/unit time): ");
    scanf("%d", &output_rate);
    printf("Enter the Bucket Size (in bytes): ");
    scanf("%d", &bucket_size);

    for (i = 0; i < NUM_PACKETS; ++i) {
        if ((packet_size[i] + remaining_data) > bucket_size) {
            if (packet_size[i] > bucket_size)
                printf("\n\nIncoming Packet[%d] size (%d bytes) exceeds bucket capacity (%d bytes) - PACKET REJECTED!", i + 1, packet_size[i], bucket_size);
            else
                printf("\n\nBucket capacity exceeded for Packet[%d] - PACKET REJECTED!", i + 1);
        } else {
            remaining_data += packet_size[i];
            printf("\n\nIncoming Packet[%d] size: %d bytes", i + 1, packet_size[i]);
            printf("\nTotal bytes to transmit (in bucket): %d", remaining_data);
            transmission_time = get_random(4) * 10;
            printf("\nEstimated transmission time: %d units", transmission_time);
            for (clock_tick = 10; clock_tick <= transmission_time; clock_tick += 10) {
                sleep(1);
                if (remaining_data > 0) {
                    if (remaining_data <= output_rate) {
                        transmitted = remaining_data;
                        remaining_data = 0;
                    } else {
                        transmitted = output_rate;
                        remaining_data -= output_rate;
                    }
                    printf("\nTransmitted %d bytes ---- Remaining in bucket: %d bytes", transmitted, remaining_data);
                } else {
                    printf("\nNo data to transmit at time unit %d!", clock_tick);
                }
            }
        }
    }
    return 0;
}
