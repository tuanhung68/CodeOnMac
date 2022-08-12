#include <iostream>
#include <string>
#include <list>
using namespace std;

struct YouTubeChannel{
    // public by default in a struct
    string Name;
    int SubscriberCount;
    // member
    
    YouTubeChannel(string name, int subscriberCount){
        Name = name;
        SubscriberCount = subscriberCount;
    }
    bool operator == (const YouTubeChannel& channel) const{
        return this->Name == channel.Name;
    }
};
ostream& operator << (ostream& COUT, YouTubeChannel& ytChannel){
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subcribers: " << ytChannel.SubscriberCount << endl;
    return COUT;
}

struct MyCollection{
    list<YouTubeChannel>myChannels;

    void operator += (YouTubeChannel& channel){
        this->myChannels.push_back(channel);
        // this is the object, this = myCollection in this case
    }
    void operator -= (YouTubeChannel& channel){
        this->myChannels.remove(channel);
        // this is the object, this = myCollection in this case
    }
};
// global function
ostream& operator << (ostream& COUT, MyCollection& myCollection){
    // for each loop
    for(YouTubeChannel ytChannel:myCollection.myChannels){
        COUT << ytChannel << endl;
    }
    return COUT;
};
int main(){
    // create an object of youtube channel type
    YouTubeChannel yt1 = YouTubeChannel("Code", 75000);
    YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);
    // << insertion operator
    //cout << yt1;
    //operator << (cout, yt1);
    MyCollection myCollection;
    // myCollection will be automatically available
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;
    cout << myCollection;


    return 0;
}