#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void drawFortuneCard() {
    vector<string> cards = {"Suan Krua", "Moitgure", "Aoa Mue", "Hom Bun", "Regular Customer", "Moldy Cutting Board", "Hom poy", "Ngan Katin", "The Kitchen", "Rainy Season", "Broken Mortar", "Flipped Tray"};
    
    int randomCards = rand() % cards.size(); // สุ่มดัชนีการ์ด
    string selectedCard = cards[randomCards]; // เก็บการ์ดที่สุ่มได้

    cout << "Gangster's Fortune Card: " << selectedCard << endl;

    if (selectedCard == "Suan Krua") {
        cout << "Many of the spices in Chili Laap are found in Lanna gardens and today you have the opportunity to visit that garden and pick up the brown spices you want.\n";
    } else if (selectedCard == "Moitgure") {
        cout << "Good chili paste is dry. Moisture causes chili paste to clump and mold. Your spices have moisture that will ruin your chili paste. Pick up 1 brown spice and return it to the center pile.\n";
    } else if (selectedCard == "Aoa Mue") {
        cout << "You are about to do a big job. Working together on big jobs like farming, harvesting rice or building a house will require a lot of manpower, which will require making laab to feed a lot of people. Your friends will share the things you need with you in a friendly manner to get 1 orange token you need from the friend on your right.\n";
    } else if (selectedCard == "Hom Bun") {
        cout << "You are holding a merit-making ceremony at your house and are making Laab for a large group of people. Your friends share the things they want with you in a friendly manner. You can pick up 1 brown token from your friend on your left.\n";
    } else if (selectedCard == "Regular Customer") {
        cout << "Being a regular at the butcher shop gives you the chance to choose quality meat before anyone else. Pick up one of the red tokens you want.\n";
    } else if (selectedCard == "Moldy Cutting Board") {
        cout << "The cutting board for making larb must be dry and clean. Failure to store the cutting board causes mold and damages the meat. Pick up 1 red poden. Return to the center pile.\n";
    } else if (selectedCard == "Hom poy") {
        cout << "You are holding a merit-making ceremony at your house and are making Laab for a large group of people. Your friends share the things they want with you in a friendly manner. You can pick up 1 red token from your friend on your left.\n";
    } else if (selectedCard == "Ngan Katin") {
        cout << "You are holding a merit-making ceremony at your house and are making Laab for a large group of people. Your friends share the things they want with you in a friendly manner. You can pick up 1 green token from your friend on your left.\n";
    } else if (selectedCard == "The Kitchen") {
        cout << "Many of the spices in chili paste are found in the kitchen garden. Just pick up one orange spice of your choice.\n";
    } else if (selectedCard == "Rainy Season") {
        cout << "The humid rainy season brings forth many kinds of vegetables that are perfect for eating with laab. Pick up any green token you want.\n";
    } else if (selectedCard == "Broken Mortar") {
        cout << "Mortar is a tool used to finely pound spices and turn them into chili paste. Your mortar spoiled the prepared spices. Pick up 1 orange spice and return it to the center pile.\n";
    } else if (selectedCard == "Flipped Tray") {
        cout << "You prepared the vegetables and the laab well, but unfortunately you made 1 piece of green yin poden tray back to the center.\n";
    }
}

int main() {
    srand(time(0)); // ตั้งค่า seed สำหรับการสุ่ม
    drawFortuneCard();
    return 0;
}
