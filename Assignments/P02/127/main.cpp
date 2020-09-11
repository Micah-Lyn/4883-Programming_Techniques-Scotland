
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{

    string card;

    while (cin >> card && card != "#")
    {

        stack<string> val;
        vector<stack<string>> cardDeck;

        val.push(card);
        cardDeck.push_back(val);

        for (int i = 1; i < 52; i++)
        {

            stack<string> val;

            cin >> card;

            val.push(card);
            cardDeck.push_back(val);
        }

        for (int c = 1; c < cardDeck.size(); c++)
        {

            if (c >= 3 && (cardDeck[c].top().at(0) == cardDeck[c - 3].top().at(0) || cardDeck[c].top().at(1) == cardDeck[c - 3].top().at(1)))
            {

                cardDeck[c - 3].push(cardDeck[c].top());
                cardDeck[c].pop();

                if (cardDeck[c].empty())
                    cardDeck.erase(cardDeck.begin() + c, cardDeck.begin() + c + 1);

                c = c - 4;
            }
            if (c >= 1 && (cardDeck[c].top().at(0) == cardDeck[c - 1].top().at(0) || cardDeck[c].top().at(1) == cardDeck[c - 1].top().at(1)))
            {

                cardDeck[c - 1].push(cardDeck[c].top());
                cardDeck[c].pop();

                if (cardDeck[c].empty())
                    cardDeck.erase(cardDeck.begin() + c, cardDeck.begin() + c + 1);
                c = c - 2;
            }
        }

        int pile = cardDeck.size();

        if (pile == 1)
        {

            cout << "1 pile remaining: ";
        }
        else
        {

            cout << pile << " piles remaining: ";
        }
        for (int i = 0; i < pile; i++)
        {

            cout << cardDeck[i].size();

            if (i != cardDeck.size() - 1)
                cout << " ";
        }

        cout << '\n';
    }
    return 0;
}