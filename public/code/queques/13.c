// 13. Find the first circular tour that visits all petrol pumps
#include < stdio.h >

int canCompleteCircuit(int petrol[][2], int n) {
    int totalPetrol = 0, totalDistance = 0;
    int currentPetrol = 0, startIndex = 0;

    
    for (int i = 0; i < n; i++) {
        totalPetrol += petrol[i][0];      
        totalDistance += petrol[i][1];   
    }

  
    if (totalPetrol < totalDistance) {
        return -1;
    }


    for (int i = 0; i < n; i++) {
        currentPetrol += petrol[i][0] - petrol[i][1]; 
      
        if (currentPetrol < 0) {
            startIndex = i + 1; 
        }
    }

    return startIndex; 
}


int main() {
    int petrol[][2] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}; // Example input
    int n = sizeof(petrol) / sizeof(petrol[0]); // Number of petrol pumps
    
    int result = canCompleteCircuit(petrol, n);
    if (result != -1) {
        printf("First circular tour can start at index: %d\n", result);
    } else {
        printf("No circular tour is possible.\n");
    }

   
    int petrol2[][2] = {{6, 4}, {3, 6}, {7, 3}};
    n = sizeof(petrol2) / sizeof(petrol2[0]);
    
    result = canCompleteCircuit(petrol2, n);
    if (result != -1) {
        printf("First circular tour can start at index: %d\n", result);
    } else {
        printf("No circular tour is possible.\n");
    }

    return 0;
}



