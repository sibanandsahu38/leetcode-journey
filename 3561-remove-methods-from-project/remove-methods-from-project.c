/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    int* outDegree = calloc(n, sizeof(int));

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        outDegree[u]++;
    }

    int** adj = malloc(n * sizeof(int*));
    int* index = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = malloc(outDegree[i] * sizeof(int));
    }

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];

        adj[u][index[u]++] = v;
    }

    bool* suspicious = calloc(n, sizeof(bool));
    suspicious[k] = true;

    int* queue = malloc(n * sizeof(int));
    int front = 0;
    int back = 0;

    queue[back++] = k;

    while (front < back) {
        int u = queue[front++];

        for (int i = 0; i < outDegree[u]; i++) {
            int v = adj[u][i];

            if (!suspicious[v]) {
                suspicious[v] = true;
                queue[back++] = v;
            }
        }
    }

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];

        if (!suspicious[u] && suspicious[v]) {
            int* result = malloc(n * sizeof(int));

            for (int j = 0; j < n; j++) {
                result[j] = j;
            }

            *returnSize = n;

            for (int j = 0; j < n; j++) {
                free(adj[j]);
            }

            free(adj);
            free(outDegree);
            free(index);
            free(suspicious);
            free(queue);

            return result;
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i]) {
            count++;
        }
    }

    int* result = malloc(count * sizeof(int));
    int resultIndex = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i]) {
            result[resultIndex++] = i;
        }
    }

    *returnSize = count;

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }

    free(adj);
    free(outDegree);
    free(index);
    free(suspicious);
    free(queue);

    return result;
}