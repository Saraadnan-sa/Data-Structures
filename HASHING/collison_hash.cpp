#include <iostream>
using namespace std;

class HashNode
{
public:
    int key;
    int value;
    HashNode *next;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashTable
{
private:
    int length;
    HashNode **valueArray;

public:
    HashTable(int length)
    {
        this->length = length;
        valueArray = new HashNode *[length];
        for (int i = 0; i < length; i++)
        {
            valueArray[i] = NULL;
        }
    }
    int hash(int key)
    {
        return key % length;
    }

    void insert(int key, int value)
    {
        int index = hash(key);
        if (valueArray[index] == NULL)
        {
            valueArray[index] = new HashNode(key, value);
        }

        else
        {
            HashNode *temp = valueArray[index];
            HashNode *prev = NULL;
            while (temp != NULL)
            {
                if (temp->key == key)
                {
                    cout << "Key " << key << " already exists" << endl;
                    return;
                }

                prev = temp;
                temp = temp->next;
            }
            prev->next = new HashNode(key, value);
        }
    }

    void find(int key)
    {
        int index = hash(key);
        if (valueArray[index] == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }
        else
        {
            HashNode *temp = valueArray[index];
            while (temp != NULL)
            {
                if (temp->key == key)
                {
                    cout << "Value found: " << temp->value << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Value not found" << endl;
        }
    }

    void remove(int key)
    {
        int index = hash(key);
        if (valueArray[index] == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }
        else
        {
            HashNode *temp = valueArray[index];
            HashNode *prev = NULL;
            while (temp = NULL)
            {
                if (temp->key == key)
                {
                    if (prev == NULL)
                    {
                        valueArray[index] = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    delete temp;
                    cout << "value deleted" << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Value not found" << endl;
        }
    }
    };
