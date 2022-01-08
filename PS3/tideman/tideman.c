#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

typedef struct {
    int winner;
    int loser;
    int m_o_v;
} w_l_m;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
        
        for (int j = 0; j < candidate_count; j++) {
            for (int k = 0; k < candidate_count; k++) {
                printf("%d ",preferences[j][k]);
            }
            printf("\n");
        }
        printf("\n");//#debugging by printing
    }
    add_pairs();
    for (int i = 0; i < pair_count; i++) {
        printf("before sorting: \n");
        printf("winner: %i, loser: %i\n", pairs[i].winner, pairs[i].loser);
    }
    sort_pairs();
    for (int i = 0; i < pair_count; i++) {
        printf("after sorting: \n");
        printf("winner: %i, loser: %i\n", pairs[i].winner, pairs[i].loser);
    }
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name, candidates[i]) == 0) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++) { 
        for (int j = i+1; j < candidate_count; j++) {
            if (i < j) {
                preferences[ranks[i]][ranks[j]] += 1;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            if (preferences[i][j] > preferences[j][i]) {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void merge_sort (int input[], int p, int r) {

    if (p < r) {
        int q = (p+r)/2 + 1;
        merge_sort(input, p, q);
        merge_sort(input, q, r);

        //merging
        int a = 0;
        int b = q;
        int c = p;
        int temp_array[r - p + 1];
        memset(temp_array, 0, r - p + 1);

        while (a < q && b <= r) {
            if (input[a] > input[b]) {
                temp_array[c] = input[a];
                a++;
                c++;
            }
            else if (input[b] > input[a]) {
                temp_array[c] = input[b];
                b++;
                c++;
            }
            else {
                temp_array[c] = input[a];
                a++;
                c++;
                temp_array[c] = input[b];
                b++;
                c++;
            }
        }

        while (a < q) {
            temp_array[c] = input[a];
            a++;
            c++;
        }
        while (b <= r) {
            temp_array[c] = input[b];
            b++;
            c++;
        }

        input = temp_array;

    }
}

void sort_pairs(void)
{
    // TODO

    int margin_of_victory[pair_count];
    w_l_m pairs_and_margin[pair_count];
    
    for (int i = 0; i < pair_count; i++) {
        pairs_and_margin[i].winner = pairs[i].winner;
        pairs_and_margin[i].loser = pairs[i].loser;
        margin_of_victory[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        pairs_and_margin[i].m_o_v = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }
    


    merge_sort(margin_of_victory, 0, sizeof(margin_of_victory));
    pair sorted_pairs[pair_count];

    for (int i = 0; i < pair_count; i++) {
        for (int j = 0; j < pair_count; j++) {
            if (margin_of_victory[i] == pairs_and_margin[j].m_o_v) {
                sorted_pairs[i].winner = pairs_and_margin[j].winner;
                sorted_pairs[i].loser = pairs_and_margin[j].loser;
                break;
            }
        }
    }

    for (int i = 0; i < pair_count; i++) {
        pairs[i].winner = sorted_pairs[i].winner;
        pairs[i].loser = sorted_pairs[i].loser;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}