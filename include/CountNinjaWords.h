#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>

// Time complexity is N*M (N is the number of target words, M is the number of chars of the sentence)
static int countNinjaWords(std::vector<std::string> targetWords, std::string sentence) 
{
    // total points
    int pts = 0;

    // iterate word by word:: time complexity *N (number of words)
    for (int i = 0; i < targetWords.size(); ++i)
    {
        // only maximum point will be added to pts
        int maxPts = 0;

        // get a word and make it lower
        std::string word = targetWords[i];
        std::transform(word.begin(), word.end(), word.begin(), 
            [](unsigned char c) { return std::tolower(c); });
        
        // In case that the sentence was "Toto to" and the target word was "toto",
        // if you pass the second 't', you won't be able to detect the ninja word, "to to".
        // In this case, possibleStartIdx will be 2.
        int possibleStartIdx = -1;

        // get the first char of dealing word to get the possibleStartIndex.
        char firstChar = word[0];

        // iterate the sentence:: time complexity *M (number of chars of the sentence)
        for (int j = 0; j < sentence.length(); )
        {
            bool isNinja = false;
            int numOfStars = 0;

            // it's the same as the number of stars in the sentence,
            // which means it could be the number of skips since the star
            // acts as any character including the space.
            int canSkip = 0; 

            // reinitialize it with -1
            possibleStartIdx = -1;

            if (tolower(sentence[j]) == word[0] || sentence[j] == '*')
            {
                // if the target word's length is zero, it doesn't need to
                // be checked.
                if (word.length() == 1)
                {
                    maxPts = std::max(maxPts, sentence[j] == '*' ? 2 : 1);
                }
                else
                {
                    // var k is an index of the target word.
                    // It is assured that the index can be 1 not causing index error
                    // as we checked the word's length right above.
                    // Also, we don't need to check the first char again so it starts
                    // with 1.
                    int k = 1;

                    // if the first char was asterisk/star, then k should start
                    // with 0, but increment canSkip by 1, which basically gives it
                    // a chance to be any character.
                    // For example, sentence was "*ea", and target word was "sea",
                    // *(star) isn't the same as the first char of the word, 's' so it
                    // gives a chance to skip it.
                    // Next it will compare the second index of the target word, 'e',
                    // with 'e' of "*ea".
                    if (sentence[j] == '*')
                    {
                        canSkip += 1;
                        numOfStars += 1;
                        k = 0;
                    } 

                    // No need to compare the first char so increment it by 1.
                    j++;

                    while (j < sentence.length())
                    {
                        // set the possible start index only one time. 
                        // if the sentence was "To sto to", and the target word was "toto",
                        // then it has to capture 4th char 't' to get a correct ninja word.
                        // BUT it must not capture 7th char 't'.
                        if (tolower(sentence[j]) == firstChar && possibleStartIdx == -1)
                        {
                            possibleStartIdx = j;
                        }

                        if (tolower(sentence[j]) == (word[k]))
                        {
                            ++j;
                            ++k;
                        }
                        else
                        {
                            // if there's space, then isNinja flag goes up and increment only the index of sentence.
                            if (sentence[j] == ' ')
                            {
                                ++j;
                                isNinja = true;
                            }
                            else if (sentence[j] == '*')
                            {
                                ++canSkip;
                                ++numOfStars;
                                ++j;
                            }
                            else
                            {
                                // the target word's index can be incremented as many times as the number of canSkip
                                // but canSkip has to be decremented each time.
                                while (canSkip > 0 && tolower(sentence[j]) != (word[k]))
                                {
                                    ++k;
                                    --canSkip;
                                }

                                // if it's still different after skipping, then break.
                                if (tolower(sentence[j]) != (word[k]))
                                {
                                    break;
                                }
                            }
                        }

                        // if the target word is ninja, then update maxPts.
                        if (k == targetWords[i].length())
                        {
                            if (isNinja || canSkip > 0)
                            {
                                int points = 1 + numOfStars;
                                maxPts = std::max(maxPts, points);
                            }
                            break;
                        }
                    }

                    // there could be a possibleStartIndex, so update index j to that.
                    if (possibleStartIdx != -1)
                    {
                        j = possibleStartIdx;
                    }
                }
            }
            else
            {
                ++j;
            }
        }
        pts += maxPts;
    }
    return pts;
}


/*
int main()
{
    printf("%d\n", countNinjaWords({"sales", "soles"}, "tapings *les"));
    printf("%d\n", countNinjaWords({"Water", "Sea", "Beach", "Shells" }, "She sells she*lls on the shore for two sand dollar* each"));
    printf("%d\n", countNinjaWords({"Toto", "Dorothy", "Oz"}, "kes Toto to Oz"));
    printf("%d\n", countNinjaWords({ "Ninja" }, "This sentence only contains one *** ja word"));
    printf("%d\n", countNinjaWords({ "Ninja","Star","Hide","Stealth","Camouflage"}, "This sentence is special because no matter how hard you look you wont find any ninja words"));
    return 0;
}
*/
