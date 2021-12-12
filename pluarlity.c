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
    // TODO
    // Loop through the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //check if candidate is similar to what is user's vote
        if(strcmp(candidates[i].name, name) == 0)
        {
            //if similar to what user voted for, then increase the specific candidate vote and return true
            candidates[i].votes++;
            return true;
        }
    }
    //else if not similar to candidate vote return false and print invalid vote
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Create a variable and set it to 0
    int maximum_vote = 0;
    // Iterate over list of canidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Checks for candidate votes that are greater than the maximum_vote and set them to maximum_vote
        if (candidates[i].votes > maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }
    // Iterate over list of candidates
    for(int i = 0; i < candidate_count; i++)
    {
        //Check for candidate votes that are equal to maximum vote and print them as you go
        if(candidates[i].votes == maximum_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

