#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_RESULT 10000

void random_sentence(char *article[], char *nouns[], char *verbs[], char *prepositions[], char *sentence) {
    int index = rand() % 5; // Random index for article
    int noun_index = rand() % 5; // Random index for nouns
    int verb_index = rand() % 5; // Random index for verbs
    int preposition_index = rand() % 5; // Random index for prepositions
    int article2_index = rand() % 5; // Random index for second article
    int noun2_index = rand() % 5; // Random index for second noun
    // Constructing the sentence
    sprintf(sentence, "%s %s %s %s %s %s.",
        article[index],
        nouns[noun_index],
        verbs[verb_index],
        prepositions[preposition_index],
        article[article2_index],
        nouns[noun2_index]);

    sentence[0] = toupper(sentence[0]);

}
int main() {
    char *article[] = {"the", "a", "one", "some", "any"};
    char *nouns[] = {"cat", "dog", "fish", "bird", "mouse"};
    char *verbs[] = {"jumps", "runs", "sits", "stands", "flies"};
    char *prepositions[] = {"over", "under", "on", "in", "with"};
    char sentence[MAX_RESULT];

    for(int i = 0; i < 10; i ++) {
        random_sentence(article, nouns, verbs, prepositions, sentence);
        printf("%d: %s\n", i + 1, sentence);
    }

    return 0;
}