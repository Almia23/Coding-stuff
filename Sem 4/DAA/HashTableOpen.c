#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20 // Initial size of the hash table
#define PRIME 7       // Prime number for hash function

// Node structure for the hash table
typedef struct Node
{
    int key;
    struct Node *next;
} Node;

// Hash table structure
typedef struct
{
    Node **array;
    int size;
} HashTable;

// Function to create a new node
Node *createNode(int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new hash table
HashTable *createHashTable(int size)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->size = size;
    ht->array = (Node **)malloc(size * sizeof(Node *));
    for (int i = 0; i < size; i++)
        ht->array[i] = NULL;
    return ht;
}

// Hash function
int hash(int key, int size)
{
    return key % size;
}

// Function to insert a key into the hash table
void insert(HashTable *ht, int key)
{
    int index = hash(key, ht->size);
    Node *newNode = createNode(key);
    newNode->next = ht->array[index];
    ht->array[index] = newNode;
}

// Function to search for a key in the hash table
int search(HashTable *ht, int key, int *comparisons)
{
    int index = hash(key, ht->size);
    Node *current = ht->array[index];
    *comparisons = 1; // Initialize comparison count
    while (current != NULL)
    {
        if (current->key == key)
            return 1; // Key found
        current = current->next;
        (*comparisons)++;
    }
    return 0; // Key not found
}

// Function to delete a hash table
void deleteHashTable(HashTable *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        Node *current = ht->array[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->array);
    free(ht);
}

int main()
{
    printf("Enter number of keys: ");
    int n, i, j, t;
    scanf("%d", &n);
    int keys[n];
    keys[0] = 2;
    for (i = 1; i < n; i++)
    {
        keys[i] = keys[i - 1] + 3;
    }

    printf("Size of hash table m=%d\nNumber of keys n=%d\n", TABLE_SIZE, n);
    printf("Keys: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", keys[i]);
    }
    printf("\n");
    // int keys[] = {3, 7, 12, 17, 21, 28, 31, 32, 35, 39}; // Sample keys
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Varying load factors (0.1 to 2.0)
    for (float loadFactor = 0.1; loadFactor <= 0.5; loadFactor += 0.1)
    {
        int tableSize = TABLE_SIZE / loadFactor;
        HashTable *ht = createHashTable(tableSize);

        // Insert keys into the hash table
        for (int i = 0; i < numKeys; i++)
            insert(ht, keys[i]);

        // Calculate number of comparisons for successful searches
        int totalComparisonsSuccess = 0;
        for (int i = 0; i < numKeys; i++)
        {
            int comparisons = 0;
            search(ht, keys[i], &comparisons);
            totalComparisonsSuccess += comparisons;
        }
        float avgComparisonsSuccess = (float)totalComparisonsSuccess / numKeys;

        // Calculate number of comparisons for unsuccessful searches
        int totalComparisonsFailure = 0;
        for (int i = 0; i < numKeys; i++)
        {
            int comparisons = 0;
            search(ht, keys[i] + 1, &comparisons); // Search for a key that doesn't exist
            totalComparisonsFailure += comparisons;
        }
        float avgComparisonsFailure = (float)totalComparisonsFailure / numKeys;

        printf("Load Factor: %.1f, Avg Comparisons (Success): %.2f, Avg Comparisons (Failure): %.2f\n",
               loadFactor, avgComparisonsSuccess, avgComparisonsFailure);

        deleteHashTable(ht);
    }

    return 0;
}
