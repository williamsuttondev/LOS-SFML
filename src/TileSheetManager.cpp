
#include <SFML/Graphics.hpp>
#include <cinttypes>
#include <cstdio>
#include <iostream>
#include "TileSheetManager.h"

void printXY(int x, int y){std::cout << "x: " << x << " | y: "<< y << std::endl;}


std::vector<sf::Texture> TileSheetManager::generateTileMapFromImage(sf::Image& tileSheet, int tileWidth, int tileHeight){

    std::vector<sf::Texture> textures;

    int x_size = tileSheet.getSize().x / tileWidth;
    int y_size = tileSheet.getSize().y / tileHeight;
    
    if(tileSheet.getSize().x % tileWidth != 0 ){
        std::cout << "Temporary error message, width does not divide into image width equally" << std::endl;
    }

    if(tileSheet.getSize().y % tileHeight != 0){
        std::cout << "Temporary error message, height does not divide into image height equally" << std::endl;
    }

    for(int x = 0; x < tileSheet.getSize().x / x_size; x++){

        for (int y = 0; y < tileSheet.getSize().y / y_size ; y++)
        {
            sf::Texture tex;
            sf::Image image;

            int size = 800;
            
            printXY(x_size*x,y*y_size);

            image.create(tileSheet.getSize().x,tileSheet.getSize().y);
            image.copy(tileSheet,0,0,sf::IntRect(x_size*x,y_size*y,x_size,y_size),false);

            tex.loadFromImage(image);

            textures.push_back(tex);
    
        }
        

    }

    return textures;

}






// if(tileSheet.getSize().x % tileWidth != 0 ){
    //     std::cout << "Temporary error message, width does not divide into image width equally" << std::endl;
    // }

    // if(tileSheet.getSize().y % tileHeight != 0){
    //     std::cout << "Temporary error message, height does not divide into image height equally" << std::endl;
    // }

    // int x_size = tileSheet.getSize().x / tileWidth;
    // int y_size = tileSheet.getSize().y / tileHeight;

    // for(int tilex = 0; tilex < tileWidth; tilex++){

    //     std::vector<sf::Uint8> pixels;

    //     for(int tiley = 0; tiley < tileHeight; tiley++){

    //         for(int x = 0; x < x_size; x++){

    //             for(int y = 0; y < y_size; y++){

    //                 sf::Color colorBuffer = tileSheet.getPixel(x,y+(tiley*y_size));

    //                 pixels.insert(pixels.end(),
    //                     {
    //                         colorBuffer.r,
    //                         colorBuffer.g,
    //                         colorBuffer.b,
    //                         colorBuffer.a
    //                     }
    //                 );

    //             }
    //         }           
    //     }

    //     // Save tile as a texture

    //     sf::Uint8* rawPixels = new sf::Uint8[pixels.size()]; 

    //     std::copy(pixels.begin(), pixels.end(), rawPixels);

    //     sf::Image newImage;

    //     newImage.create(x_size,y_size,rawPixels);

    //     sf::Texture texture;
    //     texture.loadFromImage(newImage);  

    //     textures.push_back(texture);

    //     // Save tile as a texture

    //     delete[] rawPixels;
    // }
