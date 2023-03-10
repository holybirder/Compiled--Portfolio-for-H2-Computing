//plurality: create a voting system using the plurality system(winner takes all)
//assignment instructions: https://cs50.harvard.edu/x/2022/psets/3/plurality/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //loop over the list of candidate names
    for (int j = 0; j < (candidate_count); j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //find maxvote first
    int maxvote = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvote)
        {
            //updating the maxvote to be largest
            maxvote = candidates[i].votes;
        }
    }
    //print out the name if the vote that a candidate gets is equal to maxvote
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvote)
        {
            printf("%s\n", candidates[i].name);
        }
    }

}
