#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
} pair;

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
void set_prefe_zero(void);
bool cycle(int winner, int loser);

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
    set_prefe_zero(); //Set the votes for each pair to zero before asking for the inputs.

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
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
// Returns true when name input given by the user matches with anyone of the candidates name.
// The rank input gives the order of preference of the candidates.
// Adds the index of matched candidate if any from candidates array to the 'rank' index of ranks[] array.
// Where rank = 0 is the first preference and rank increment upto candidate_count - 1.
// Outputs the ranks array with preference of each voter.

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
// i and j are the indices of array ranks[], where i is chosen over j.
// From observation j = i+1, i+2 ..... i+n-1. where n is the candidate_count.
// ranks[i] and ranks[j] are the indices of 2 dimensional array, 'preferences[l][k]' where,
// preference of l over k is needed to be marked by incrementing value at index [l][k] by one.

    for(int i = 0; i < candidate_count - 1; i++)
    {
        for(int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            float difference = preferences[i][j] - preferences[j][i];
         // compares each pair, where one is preferred over the other.
            if (difference != 0)
            {
                if (difference > 0)
                {
                    pairs[pair_count].winner = i; // pair_count is the index of pairs array
                    pairs[pair_count].loser = j;  // pair_count increases over each iteration if
                }                                 //  one pair is preferred over the other.
                else if ( difference < 0)
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                }
                pair_count += 1;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int pref_strength[pair_count]; // array of vote lead for each pair.
    int counter = 0;               // index of pairs with highest lead in each iteration.
    int pair_place_holder[2];      // for storing the pairs of current index in the iteration

    for (int i = 0; i < pair_count; i++)
    {
        // finding lead votes for each pair and storing it in pref_strength array.
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        pref_strength[i] = preferences[winner][loser] - preferences[loser][winner];

    }

    for (int i = 0; i < pair_count; i++)    // main loop to sort the pairs array.
    {
        pair_place_holder[0] = pairs[i].winner;
        pair_place_holder[1] = pairs[i].loser;
        int largest_lead = 0;                // temp storage for current largest value in main loop.
        for (int j = i; j < pair_count; j++) // sub loop to find the highest value and
        {                                    // its index in each iteration.
            if ( pref_strength[j] > largest_lead)
            {
                largest_lead = pref_strength[j];
                counter = j;
            }
        }
        if (counter != i)                               // checking if current value is the largest lead vote.
                                                        // if it is the case skip swapping.
        {
            pref_strength[counter] = pref_strength[i];  // swapping the highest value with current value in
                                                        // the pre_strength array.

            pairs[i].winner = pairs[counter].winner;    // swapping current pair with lead vote pair.
            pairs[i].loser = pairs[counter].loser;
            pairs[counter].winner = pair_place_holder[0];// swapping lead vote pair with current pair from place holder.
            pairs[counter].loser = pair_place_holder[1];

        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!cycle(winner,loser))
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int source = 0;
    for (int j = 0; j < candidate_count; j++)
    {
            int counter = 0;
            for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j] == true)
            {
                counter += 1;
            }
        }
            if (counter == 0)
        {
            {
                source = j;
            }
        }
    }
    printf("%s\n", candidates[source]);
   return;
}

// setting the value of preferences to '0'.
void set_prefe_zero(void)
{
     for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }
    return;
}
// function to  check can the edge cause a cycle.
bool cycle(int winner, int loser)
{
    // base case
    for (int i = 0; i < candidate_count; i++)
    {
        // finding a link from the loser to winner if exists.
        int target = winner;
        int current_candidate = i; // current candidate.
        if (locked[loser][current_candidate])
        {
            if (i == target) // looking for an edge from loser to every candidate,
            {
                return true; // if an edge exists, and the currently iterated candidate is the target.
            }                // returns true to skip that edge since it cause a cycle.
            // recursive case.
            else            // if there is a link between current candidate and loser, recursively looking for a
            {               // link between the current candidate and target, if exists.
                if (cycle(target, current_candidate))
                return true;
            }
        }
    }
    return false;
}
