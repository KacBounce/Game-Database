#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

struct GameData{
  string genre;
  string name;
  float price;
  string developer;
  double timePlayed;
  int activePlayers;
  bool adult;
};

struct database{
  static const int MaxSize = 100;
  int size = 0;
  GameData games[MaxSize];

};

void input(GameData &game){
  cout << "What is the genre of your game(RPG,FPS,Racing,etc.)?\nGenre : ";
  getline(cin,game.genre);
  cout << endl;
  cout << "What is the name of your game?\nName : ";
  getline(cin,game.name);
  cout << endl;
  cout << "How much does your game cost?\nPrice : ";
  cin >> game.price;
  cin.ignore();
  cout << endl;
  cout << "Who made your game?\nDeveloper : ";
  getline(cin,game.developer);
  cout << endl;
  cout << "How much did you play your game for?\nTime played : ";
  cin >> game.timePlayed;
  cin.ignore();
  cout << endl;
  cout << "How many gamers are active on your games server?\nActive players : ";
  cin >> game.activePlayers;
  cin.ignore();
  cout << endl;
  cout << "Is your game +18?\n(1 - Yes | 0 - No)\nNumber : ";
  cin >> game.adult;
  cin.ignore();
  cout << endl;
}

void update(GameData &game){
  int go = 1;
  while(go){
    int x;
    cout << "---CHOOSE AN ELEMENT TO CHANGE IN YOUR GAME DATA---\n1.The Genre\n2.The Name\n3.The Price\n4.The Developer\n5.The Time You've Played For\n6.Active player base\n7.Is it 18+\n8.Stop Changing And Return To Your Program\nNumber : ";
    cin >> x;
    cin.ignore();
    cout << endl;
    if(x == 1){
      cout << "What should the new genre be?\nGenre : ";
      getline(cin,game.genre);
      cout << endl;
    }
    else if(x == 2){
      cout << "What should the new name be?\nName : ";
      getline(cin,game.name);
      cout << endl;
    }
    else if(x == 3){
      cout << "What should the new price be?\nPrice : ";
      cin >> game.price;
      cin.ignore();
      cout << endl;
    }
    else if(x == 4){
      cout << "What should the new developer be?\nDeveloper : ";
      getline(cin,game.developer);
      cout << endl;
    }
    else if(x == 5){
      cout << "What should the new time played be?\nTime played : ";
      cin >> game.timePlayed;
      cin.ignore();
      cout << endl;
    }
    else if(x == 6){
      cout << "What should the new active player base be?\nActive player base : ";
      cin >> game.activePlayers;
      cin.ignore();
      cout << endl;
    }
    else if(x == 7){
      cout << "Is your game +18?\n(1 - Yes | 0 - No)\nNumber : ";
      cin >> game.adult;
      cin.ignore();
      cout << endl;
    }
    else if(x == 8){
      go = 0;
    }
  }
  cout << endl;
}

void display(GameData game){
  cout << "The name of the game : " << game.name << endl << "Game's genre : " << game.genre << endl << "Game's price : " << game.price << endl << "Game's developer : " << game.developer << endl << "Time played : " << game.timePlayed << endl << "Active player base : " << game.activePlayers << endl << "18+ : " << game.adult << endl << endl;
}

void read_add(database &data){
  int x;
  int z;
  cout << "Do you want to:\n1.Read an existing element\n2.Add new element\nNumber : ";
  cin >> x;
  cin.ignore();
  cout << endl;
  if(x == 1){
    cout << "Enter the number of the element you want to read : ";
    cin >> z;
    cin.ignore();
    display(data.games[z]);
  }
  else if(x == 2){
    input(data.games[data.size]);
    if(data.size == 100){
      cout << "You have reached the maximum number of elements\n";
    }
    else{
      data.size++;
    }
  }
}

void display_all(database data){
  for(int i = 0;i<data.size;i++){
    display(data.games[i]);
  }
}

void update_data(database &data){
  int x;
  cout << "Enter the number of the element you want to modify : ";
  cin >> x;
  cin.ignore();
  cout << endl;
  update(data.games[x]);
}

void remove(database &data){
  int x;
  cout << "Enter the number of the element you want to delete : ";
  cin >> x;
  cin.ignore();
  cout << endl;
  for(int i = 5;i<data.size;i++){
    data.games[i] = data.games[i+1];
  }
  data.size--;
}

void filter(database data){
  GameData criteria;
  int go = 1;
  int x;
  int min_max;
  int counter = 0;
  int counter1 = 0;
  while(go){
    cout << "What do you want to add to the filter:\n1.Game genre\n2.Minimum price\n3.Maximum price\n4.The developer\n5.Stop adding and search for your game\nNumber : ";
    cin >> x;
    cin.ignore();
    cout << endl;
    if(x == 1){
      cout << "What is the genre of the game you're looking for?(RPG,FPS,Racing,etc.)?\nGenre : ";
      getline(cin,criteria.genre);
      cout << endl;
      counter++;
    }
    else if(x == 2){
      cout << "What is the minimum price of the games you're looking for? : ";
      cin >> criteria.price;
      cin.ignore();
      cout << endl;
      min_max = 0;
      counter++;
    }
    else if(x == 3){
      cout << "What is the maximum price of the games you're looking for? : ";
      cin >> criteria.price;
      cin.ignore();
      cout << endl;
      min_max = 1;
      counter++;
    }
    else if(x == 4){
      cout << "What is the developer of the games you're looking for? : ";
      getline(cin,criteria.developer);
      cout << endl;
      counter++;
    }
    else if(x == 5){
      go = 0;
    }
  }
  for(int i = 0;i<data.size;i++){
    counter1 = 0;
    if(data.games[i].genre == criteria.genre){
      counter1++;
    }
    if(data.games[i].developer == criteria.developer){
      counter1++;
    }
    if(min_max == 0 && data.games[i].price >= criteria.price){
      counter1++;
    }
    if(min_max == 1 && data.games[i].price <= criteria.price){
      counter1++;
    }
    if(counter1 == counter){
      display(data.games[i]);
    }
  }
}

void saver(database &data,const char *file_name){
  ofstream save(file_name, ios::out | ios::binary);
  if(!save){
    cout << "Something went wrong\n\n";
  }
  else{
    save.write((char*)&data,sizeof(struct database));
    save.close();
  }
}

void loader(database &data,const char *file_name){
  ifstream save (file_name, ios::in | ios::binary);
  if(!save){
    cout << "Something went wrong\n\n";
  }
  else{
    save.read((char*)&data,sizeof(struct database));
    save.close();
  }
}

//another implementation not used here
void saver1(database &data,const char *file_name){
  FILE *save;
  save = fopen(file_name,"wb");
  if(save == NULL){
    cout << "Something went wrong\n\n";
  }
  else{
    fwrite(&data,sizeof(data),1,save);
    fclose(save);
  }
}

void loader1(database &data,const char *file_name){
  FILE *save;
  save = fopen(file_name,"rb");
  if(save == NULL){
    cout << "Something went wrong\n\n";
  }
  else{
    fread(&data,sizeof(data),1,save);
    fclose(save);
  }
}

void ctd(char *ptr){
  *ptr = '.';
}

void exporter(database data){
  ofstream file;
  file.open("C:\\ProgramData\\Programming\\Projects\\C++\\1stSemester\\LAB14\\database.csv",ios::out);
  for(int i = 0;i<data.size;i++){
    file << data.games[i].genre << ";";
    file << data.games[i].name << ";";
    file << data.games[i].price << ";";
    file << data.games[i].developer << ";";
    file << data.games[i].timePlayed << ";";
    file << data.games[i].activePlayers << ";";
    file << data.games[i].adult <<  endl;
  }
  file.close();
}

void importer(database &data){
  FILE *file;
  file = fopen("C:\\ProgramData\\Programming\\Projects\\C++\\1stSemester\\LAB14\\database.csv","r");
  char buffer[500] = "";
  char text[500] = "";
  char test[500] = "";
  int possition = 0;
  int j = 0;
  int counter = 0;
  stringstream ss;
  while(fgets(buffer,500,file)!=NULL){
    j = 0;
    for(int i = possition;i<possition+strlen(buffer);i++){
      text[i] = buffer[j];
      j++;
    }
    possition += strlen(buffer);
    counter++;
  }
  data.size = counter;
  fclose(file);
  char *games = strtok(text, ";");
  ss.clear();
  j = 0;
  while(games!=NULL){
    data.games[j].genre = games;
    games = strtok(NULL,";");
    data.games[j].name = games;
    games = strtok(NULL,";");
    char *ptr = strchr(games,',');
    if(ptr != NULL){
      ctd(ptr);
    }
    ss << games;
    float price;
    ss >> price;
    ss.clear();
    data.games[j].price = price;
    games = strtok(NULL,";");
    data.games[j].developer = games;
    games = strtok(NULL,";");
    ptr = strchr(games,',');
    if(ptr != NULL){
      ctd(ptr);
    }
    ss << games;
    double time;
    ss >> time;
    ss.clear();
    data.games[j].timePlayed = time;
    games = strtok(NULL,";");
    ss << games;
    int play;
    ss >> play;
    ss.clear();
    data.games[j].activePlayers = play;
    games = strtok(NULL,"\n");
    int boo;
    ss << games;
    ss >> boo;
    ss.clear();
    data.games[j].adult = boo;
    games = strtok(NULL,"\n;");
    j++;
  }
}


int main(){
  int x;
  int go = 1;
  database gamedata;
  while(go){
    cout << "DATABASE SIZE : " << gamedata.size << endl;
    cout << "What do you want to do with your database:\n1.Read or add new element\n2.Display all the elements\n3.Update an element\n4.Delete an element\n5.Search using a filter\n6.Save\n7.Load\n8.Export data to text file\n9.Import data from text file\n10.Exit the program\nNumber : ";
    cin >> x;
    cin.ignore();
    cout << endl;
    if(x == 1){
      read_add(gamedata);
    }
    else if(x == 2){
      display_all(gamedata);
    }
    else if(x == 3){
      update_data(gamedata);
    }
    else if(x == 4){
      remove(gamedata);
    }
    else if(x == 5){
      filter(gamedata);
    }
    else if(x==6){
      saver(gamedata,"C:\\ProgramData\\Programming\\Projects\\C++\\1stSemester\\LAB14\\savedat.dat");
    }
    else if(x==7){
      loader(gamedata,"C:\\ProgramData\\Programming\\Projects\\C++\\1stSemester\\LAB14\\savedat.dat");
    }
    else if(x == 8){
      exporter(gamedata);
    }
    else if(x == 9){
      importer(gamedata);
    }
    else if(x == 10){
      go = 0;
    }
    else{
      cout << "That's not an option\n";
    }
  }
}
