#include<iostream>
#include<fstream>
#include <string>
#include <conio.h>
#include <algorithm>
#include<vector>
using namespace std;

string alpha="abcdefghijklmnopqrstuvwxyz";
fstream file;
vector<string> correct;

int missingCharacter(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len+1==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<=len;i++)
        {
            for(int j=0;j<26;j++)
            {
                string chinput=input;
                chinput.insert(i,1,alpha[j]);
                if(word==chinput)
                {
                    found=1;
                    if(std::find(correct.begin(),correct.end(),chinput)!=correct.end())
                        break;
                    else
                    {
                        correct.push_back(chinput);
                        cout<<chinput<<endl;
                    }
                }
            }
        }
    }
    file.close();
    return found;
}
int exchangedCharacters(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<26;j++)
            {
                string chinput=input;
                chinput[i]=alpha[j];
                if(word==chinput)
                {
                    found++;
                    if(std::find(correct.begin(),correct.end(),chinput)!=correct.end())
                        break;
                    else{
                        correct.push_back(chinput);
                        cout<<chinput<<endl;
                        if(found==4)
                            return 1;
                    }
                }
            }
        }
    }
    file.close();
    return found;
}
int extraCharacter(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len-1==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<len;i++)
        {
            string chinput=input,chinput2="";
            for(int j=0;j<len;j++){
                if(j!=i)
                    chinput2+=chinput[j];
            }
            if(word==chinput2)
            {
                found=1;
                if(std::find(correct.begin(),correct.end(),chinput2)!=correct.end())
                    break;
                else{
                    correct.push_back(chinput2);
                    cout<<chinput2<<endl;
                }
            }
        }
    }
    file.close();
    return found;
}
int mixedExtraMissing(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<=len;i++)
        {
            for(int j=0;j<26;j++)
            {
                string chinput=input,chinput2="";
                chinput.insert(i,1,alpha[j]);
                for(int k=0;k<=len;k++)
                {
                    for(int l=0;l<=len;l++){
                        if(l!=k||i==k)
                            chinput2+=chinput[l];
                    }
                    if(word==chinput2)
                    {
                        found++;
                        if(std::find(correct.begin(),correct.end(),chinput2)!=correct.end())
                            break;
                        else{
                            correct.push_back(chinput2);
                            cout<<chinput2<<endl;
                            if(found==2)
                                return 1;
                        }
                    }
                }
            }
        }
    }
    file.close();
    return found;
}
int mixedExchangeMissing(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len+1==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<=len;i++)
        {
            for(int j=0;j<26;j++)
            {
                string chinput=input;
                chinput.insert(i,1,alpha[j]);
                for(int k=0;k<=len;k++)
                {
                    if(i!=k){
                        for(int l=0;l<26;l++)
                        {
                            chinput[k]=alpha[l];
                            if(word==chinput)
                            {
                                found++;
                                if(std::find(correct.begin(),correct.end(),chinput)!=correct.end())
                                    break;
                                else{
                                    correct.push_back(chinput);
                                    cout<<chinput<<endl;
                                    if(found==3)
                                        return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    file.close();
    return found;
}
int mixedExchangeExtra(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len-1==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<len;i++)
        {
            string chinput=input,chinput2="";
            for(int j=0;j<len;j++){
                if(j!=i)
                    chinput2+=chinput[j];
            }
            for(int k=0;k<len-1;k++)
            {
                if(i!=k){
                    for(int l=0;l<26;l++)
                    {
                        chinput2[k]=alpha[l];
                            if(word==chinput2)
                            {
                                found++;
                                if(std::find(correct.begin(),correct.end(),chinput2)!=correct.end())
                                    break;
                                else{
                                    correct.push_back(chinput2);
                                    cout<<chinput2<<endl;
                                    if(found==2)
                                        return 1;
                                }
                            }
                        }
                    }
                }
            }
    }
    file.close();
    return found;
}
int incorrectArrangement(string input,int len)
{
    int found=0;
    string word;
    file.open("words.txt");
    while(file >> word) {
        int wlen=word.length();
        if(len==wlen&&(input[0]+input[1]==word[0]+word[1]||input[len-2]+input[len-1]==word[wlen-2]+word[wlen-1]
                         ||input[len/2-1]+input[len/2]==word[wlen/2-1]+word[wlen/2]))
        for(int i=0;i<len-1;i++)
        {
            string chinput=input,temp;
            temp=chinput[i];
            chinput[i]=chinput[i+1];
            chinput[i+1]=temp[0];
            if(word==chinput)
            {
                found=1;
                if(std::find(correct.begin(),correct.end(),chinput)!=correct.end())
                    break;
                else{
                    correct.push_back(chinput);
                    cout<<chinput<<endl;
                }
            }
        }
    }
    file.close();
    return found;
}
int main() {
    while (1) {
        string input,word;
        int len,c=0,vlen;
        cout<<"Enter the word: ";
        getline(cin,input);
        transform(input.begin(),input.end(),input.begin(),::tolower);
        len = input.length();
        file.open("words.txt");
        if(len>1){
        if(file)
        {
            while (file>>word)
            {
                    if (word==input)
                    {
                        c=1;
                    }
                    else continue;
            }
            file.close();
            if (c==1)
            {
                cout<<endl<<"Spelling is correct"<<endl;
            }
            if (c==0)
            {
                int missing = 0, extra = 0, mixed1 = 0, mixed2 = 0, mixed3 = 0, incorrect = 0, exchanged = 0;
                cout<<endl<<"Spelling is wrong. \nPossible right spellings are given below:- \tLoading Please Wait at least 10 sec....."<<endl<<endl;
                missing = missingCharacter(input,len);
                exchanged = exchangedCharacters(input,len);
                if(exchanged==0){
                    extra = extraCharacter(input,len);
                    if(extra==0){
                        incorrect = incorrectArrangement(input,len);
                        if(incorrect==0){
                            mixed1 = mixedExtraMissing(input,len);
                            if(mixed1==0){
                                mixed2 = mixedExchangeMissing(input,len);
                                if(mixed2==0){
                                    mixed3 = mixedExchangeExtra(input,len);
                                }
                            }
                        }
                    }
                }
                if (missing == 0 && extra == 0 && mixed1 == 0 && mixed2 == 0 && mixed3 == 0 && incorrect == 0 && exchanged == 0)
                {
                    cout<<endl<<"No such word exist"<<endl;
                }
            }
        }
        else
        {
            cout<<"Not able to open words.txt"<<endl;
        }
        }
        else
            cout<<"Wrong Input!! Not a Word";
        cout<<endl<<"Press any key to continue...And to exit press E"<<endl<<endl;
        if(_getch()=='E')
            return 0;
    }
    return 0;
}
