#include <stdio.h>

int main() {

}

int majority_element(const int *parr, int len) {
    
    int m1, m2;

    if (len / 2 != 0) {
        int i, m1_count, m2_count;
        m1 = majority_element(parr, len / 2);
        m2 = majority_element(parr + len / 2, len / 2);
        for (i = 1; i <= len; i++) {
            if (parr[i] == m1) m1_count++; 
            if (parr[i] == m2) m2_count++; 
        }
        if (m1_count > m2_count) return m1; 
            else if (m2_count > m1_count) return m2;
                else return -1;
    } else {
        return *parr;
    }
}