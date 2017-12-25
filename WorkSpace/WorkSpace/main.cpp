#include "TEA.h"
#include <cstdio>
#include <iostream>

#include "dijkstra.h"

using namespace std;

int test_TEA() {
    long v[2]; /* Plaintext */
    long k[4]; /* Key */
    long w[2]; /* cipher text */
                        /* Input to Plain Text */
    v[0] = 0x12345678; v[1] = 0x33333333;
    printf("\n\nInput Data: ");
    printf(" v = 0x%x 0x%x\n\n", v[0], v[1]);
    /* Key */
    k[0] = 0x00000000; k[1] = 0x80000000;
    k[2] = 0x80000000; k[3] = 0x80000000;
    printf("Key = 0x%x 0x%x 0x%x 0x%x\n\n", k[0], k[1], k[2], k[3]);

    ws::Encrypt(v, k);
    printf("\nEncoded data = 0x%x 0x%x\n", v[0], v[1]);
    printf("Key = 0x%x 0x%x 0x%x 0x%x\n\n", k[0], k[1], k[2], k[3]);

    w[0] = v[0];
    w[1] = v[1];

    ws::Decrypt(v, k);
    printf("\nDecoded data = 0x%x 0x%x\n", v[0], v[1]);
    printf("Key = 0x%x 0x%x 0x%x 0x%x\n\n", k[0], k[1], k[2], k[3]);

    return 0;
}

// driver program to test above function
int test_dijkstra() {
    /* Let us create the example graph discussed above */
    int graph[V][V] = { 
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    ws::dijkstra(graph, 0);

    return 0;
}

int test_str_func() {
    char s[] = "ab-cd : ef gh;jksh:z";
    char* delim = "-: ";
    char* p;
    printf("%s ", strtok(s, delim));
    while (p = strtok(NULL, delim)) {
        printf("%s ", p);
    }
    printf("\n");
    return 0;
}

int test_string()
{
    string str = "p edge 125 736";

    string str_out;
    char ch_var[1024];
    char ch_out[1024];
    char ch;
    int node_num, edge_num;

    sscanf(str.c_str(), "%c %s %d %d", &ch, ch_var, &node_num, &edge_num);

    sprintf(ch_out, "%c %s %d %d, xixi", ch ,ch_var, node_num, edge_num);

    return 0;
}

int main(int argc, char* argv[]) {
    //test_TEA();

    //test_dijkstra();

    //test_str_func();

    test_string();

    return 0;
}