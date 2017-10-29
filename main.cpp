
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Tile.hpp"
#include <vector>


// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

using namespace sf;

Game game;

Font systemFont;
Texture player_texture;
int width = 1200;
int game_width = 800;

int tileSize  = 200;
//Draw grid for tiles on window
void drawGrid(RenderWindow & window){
   
    for(int i = 0; i < 50; i++){
        RectangleShape line(Vector2f(200,5));
        line.setFillColor(Color::Black);

        line.setPosition(tileSize * i  , 700);
        line.rotate(90);
        window.draw(line);
    }
}

int calc_size_map(){
    return game_width / tileSize;
}
int calc_start_x_map(){
    int start_x = game.get_player().get_pos().get_x();
    int start = start_x - (calc_size_map() / 2);
    if(start < 0){
        start = 0;
    }
    return start;
}
int calc_ground_y(){
    return 900 - tileSize;
}


Text create_text(string msg, int x, int y){
    Text name_label;
    name_label.setFont(systemFont);
    name_label.setString(msg);
    name_label.setColor(Color::White);
    name_label.setPosition(x, y);
    
    return name_label;
}
void draw_gui(RenderWindow& window){
    int stat_x_start = 10;
    int stat_y_start = 10;
    
    stringstream ss;
    ss << "User: " << game.get_player().get_username() << "\t\t\tx: " << game.get_player().get_pos().get_x() << "\ncoins: " << game.get_player().get_coins();
    
    Text name_label;
    name_label.setFont(systemFont);
    name_label.setString(ss.str());
    name_label.setColor(Color::White);
    
    Text stat_label;
    stat_label.setFont(systemFont);
    stat_label.setString(game.get_player().get_stats());
    stat_label.setColor(Color::White);
    stat_label.setPosition(stat_x_start, stat_y_start + 60);
    
    
    window.draw(stat_label);
    window.draw(name_label);
    
}

int get_tile_click(int mouse_x){
   // cout <<"tile_x: "  << (mouse_x / tileSize ) << endl;
    
    int start_x = calc_start_x_map();
    
    return (start_x + (mouse_x / tileSize));
    
}

void draw_bg(RenderWindow & window){
    window.clear();
    
    Texture sky_texture;
    sky_texture.loadFromFile(resourcePath() + "sky.png");
    
    
    Sprite tile;
    tile.setScale(140, 80);
    tile.setColor(sf::Color(255, 255, 255, 200));
    tile.setPosition(0, 0);
    tile.setTexture(sky_texture);
    
    window.draw(tile);
}

int calc_x_onscreen(){
    int num_to_render = calc_size_map();
    int start = calc_start_x_map();

    
    return (num_to_render / 2) + start;

}

void draw_tool(RenderWindow & window, int x_pos ){
    Sprite tool;
    Texture tool_texture;
    Tool cur_tool = game.get_player().get_invo().cur_tool;
    
    if(cur_tool.name != "\0"){
        if(tool_texture.loadFromFile(resourcePath() + cur_tool.name +".png")){
        }

    }
    //tool_texture.loadFromFile(resourcePath() + "axe.png");
    tool.setTexture(tool_texture);
    tool.setScale(10, 10);
    tool.setPosition(x_pos * tileSize + (100), 500 );
    
    window.draw(tool);
}

void draw_invo(RenderWindow& window){
    RectangleShape bg;
    bg.setFillColor(Color::Black);
    bg.setPosition(game_width + 200, 0);
    bg.setSize(Vector2f(400,900));
    
    
    window.draw(bg);
    stringstream css;
    css << "gp: " << game.get_player().get_coins();
    
    Text coins = create_text(css.str() , 1250, 0);
    window.draw(coins);
    
    int draw_y = 1;

    
    for(int i = 0 ; i < game.get_player().get_invo().get_items().size(); i++){
        
        stringstream ss;
        ss << game.get_player().get_invo().get_items().at(i).name;
        ss << " x " << game.get_player().get_invo().get_items().at(i).amount;
        
        Text lvl = create_text(ss.str(), game_width + 250, draw_y * 30);
        window.draw(lvl);
        draw_y++;
    }
    draw_y = 1;
    for(int i = 0 ; i < game.get_player().get_invo().get_weapons().size(); i++){
        
        stringstream ss;
        ss << game.get_player().get_invo().get_weapons().at(i).name;
        
        Text lvl = create_text(ss.str(), game_width + 450, draw_y * 30);
        window.draw(lvl);
        draw_y++;
    }
    
 
    for(int i = 0 ; i < game.get_player().get_invo().get_tools().size(); i++){
        
        stringstream ss;
        ss << game.get_player().get_invo().get_tools().at(i).name;
        
        Text lvl = create_text(ss.str(), game_width + 450, draw_y * 30);
        
        if(game.get_player().get_invo().cur_tool.name == game.get_player().get_invo().get_tools().at(i).name){
            lvl.setFillColor(Color::Green);
        }else{
            lvl.setFillColor(Color::White);
        }
        
        window.draw(lvl);
        draw_y++;
    }

}

void draw_mini_map(RenderWindow & window){
    
    for(int i = 0; i < game.get_map().width; i++){
       // Sprite
        stringstream ss;
        ss << game.get_map().map.at(i);
        Text m = create_text(ss.str(), i * 10, 30);
        window.draw(m);
    }
    
}

void draw_shop(RenderWindow & window){
    if(game.get_player().in_shop){
        RectangleShape shop;
        shop.setFillColor(Color::Blue);
        shop.setSize(Vector2f(1000,500));
        window.draw(shop);
    
    
    for(int i = 0 ; i < game.get_player().get_invo().get_items().size(); i++){
        
        stringstream ss;
        ss << game.get_player().get_invo().get_items().at(i).name << " " << game.get_player().get_invo().get_items().at(i).price;
        ss << " x" << game.get_player().get_invo().get_items().at(i).amount;
        
        Text lvl = create_text(ss.str(),  100, i * 30);
        window.draw(lvl);
        }
        
    
    
    RectangleShape cursor;
    cursor.setSize(Vector2f(200, 30));
        int x = 100;
        int y = game.get_player().get_invo().get_item_index(game.get_player().get_invo().cur_item);
    
    cursor.setPosition(100, y * 30);
    
    cursor.setFillColor(Color::Color(255,255,255,100));
        
    
    window.draw(cursor);
        
        
        
    
    }
}


void draw_buy_store(RenderWindow & window){
    if(game.get_player().in_store_buying){
        
        
        RectangleShape shop;
        shop.setFillColor(Color::Blue);
        shop.setSize(Vector2f(1000,500));
        window.draw(shop);
        
        
       
        

        for(int i = 0 ; i < game.get_shops().weapons.size(); i++){
            
            stringstream ss;
            ss << game.get_shops().weapons.at(i).name << " " << game.get_shops().weapons.at(i).cost;
            
            Text lvl = create_text(ss.str(),  100, i * 30);

          //  cout << game.get_player().get_invo().has_weapon(game.get_shops().cur_weapon.name) << endl;
            
            if(game.get_player().get_invo().has_weapon(game.get_shops().weapons.at(i).name) ){
                
                lvl.setFillColor(Color::Red);
            }else{
                lvl.setFillColor(Color::White);

            }
                       window.draw(lvl);
        }
        
        
        
        RectangleShape cursor;
        cursor.setSize(Vector2f(200, 30));
        int x = 100;
        int y = game.get_shops().get_weapon_index(game.get_shops().cur_weapon);
        
        cursor.setPosition(100, y * 30);
        
        cursor.setFillColor(Color::Color(255,255,255,100));
        
       
        
        window.draw(cursor);
        

        
    }
}

void render(RenderWindow & window){
    
    draw_bg(window);
  
    vector<Sprite> items; // all items on the screen
    Sprite player; // player sprite


    int num_to_render = calc_size_map();
    
    int player_x = game.get_player().get_pos().get_x();
    
    int start = calc_start_x_map();
    
    int drawX = 0;
    
    int ypos = calc_ground_y();
    
   // cout << "numR: " << num_to_render << " p_x: " << player_x << " s: " << start << " draw_x: " << drawX << " y: " << ypos << endl;
    
    for(int i = start; i < (num_to_render + start) + 1; i++){
        if(i < game.get_map().width){ // we are on map
            
            sf::Texture texture;
            texture.loadFromFile(resourcePath() + "dirt_tile.png");
            
            sf::Texture sword_shop;
            sword_shop.loadFromFile(resourcePath() + "sword_shop.png");
            
            sf::Texture fish_texture;
            fish_texture.loadFromFile(resourcePath() + "fish.png");
            
            sf::Texture rock_texture;
            rock_texture.loadFromFile(resourcePath() + "rock.png");

            
            Texture tree_texture;
            tree_texture.loadFromFile(resourcePath() + "tree.png");
            
            
            sf::Texture p_texture;
            p_texture.loadFromFile(resourcePath() + "player_idel.png");
            

            sf::Texture merchant_texture;
            merchant_texture.loadFromFile(resourcePath() + "merchant.png");
            
            sf::Texture wall_texture;
            wall_texture.loadFromFile(resourcePath() + "end_map.png");
            
            
            player.setTexture(p_texture);
            player.setScale(20, 20);
            player.setPosition(drawX * tileSize, ypos);
            
            
           
            player.setScale(20, 20);
            player.setPosition(drawX * tileSize, ypos);
            

            Sprite tile;
            tile.setScale(20, 20);
            tile.setColor(sf::Color(255, 255, 255, 200));
            tile.setPosition(drawX * tileSize, ypos);
            tile.setTexture(texture);

            
        
            Text l(game.get_map().map.at(i),systemFont, 50);
            l.setFillColor(Color::Black);
            l.setPosition(drawX * tileSize + 100, ypos + 40);
            
            
            
        if(i == player_x){
            //t.twoTile.setFillColor(Color::Blue);
            l.setString(game.get_map().map.at(i));
            int direction = game.get_player().get_pos().get_direction();
            if(direction == -1){
                p_texture.loadFromFile(resourcePath() + "player_left.png");
            }else{
                p_texture.loadFromFile(resourcePath() + "player_left.png");
            }
          
            
            player.setScale(1 * 10, 10);
            player.setTexture(p_texture);
            player.setPosition(drawX * tileSize  +  (  player.getGlobalBounds().width / 2 ), ypos - 10 * 30);
            
            window.draw(player);
            draw_tool(window, drawX);

        }
            
              if(game.get_map().map.at(  i) == '/'){
                  Sprite item;
                  item.setScale(20, 10);
                  item.setTexture(wall_texture);
                  item.setPosition( ( drawX * tileSize)  , ypos - 50 * 9);
                  window.draw(item);
              }
            
            if(game.get_map().map.at(  i) == '$'){
                Sprite item;
                item.setScale(10, 10);
                item.setTexture(merchant_texture);
                item.setPosition( ( drawX * tileSize) + item.getGlobalBounds().width / 4 , ypos - 30 * 10);
                window.draw(item);
            }
            
            if(game.get_map().map.at(  i) == '^'){
                Sprite item;
                item.setScale(10, 10);
                item.setTexture(sword_shop);
                item.setPosition( ( drawX * tileSize) + item.getGlobalBounds().width / 4 , ypos - 30 * 10);
                window.draw(item);
            }
        
            
            if(game.get_map().map.at(  i) == 't'){
                Sprite item;
                item.setScale(10, 10);
                item.setTexture(tree_texture);
                item.setPosition( ( drawX * tileSize) + item.getGlobalBounds().width / 2 , ypos - 10 * 40);
                window.draw(item);
              //  window.draw(tile);

            }
            
            if(game.get_map().map.at( i) == 'r'){
                Sprite item;

                item.setScale(10, 10);
                item.setTexture(rock_texture);
                item.setPosition( ( drawX * tileSize) + item.getGlobalBounds().width / 2 , ypos - 10 * 10);
                window.draw(item);
               // window.draw(tile);

            }
            
            if(game.get_map().map.at( i) == 'f'){
                Sprite item;
                
                item.setScale(10, 10);
                item.setTexture(rock_texture);
                item.setPosition( ( drawX * tileSize) + item.getGlobalBounds().width / 2 , ypos - 10 * 10);
                //window.draw(item);
                tile.setTexture(fish_texture);
                window.draw(tile);
                
            }
            
            window.draw(tile);

          
            
            drawX++;

            //cout << game.get_map().map.at(i);
            
          
            
            window.draw(l);
          
        }
       
    }
    

    
    drawGrid(window);
    draw_invo(window);
    draw_gui(window);
   
    // draw_mini_map(window);

    draw_shop(window);
    draw_buy_store(window);
    
 
}



//interacts with tile
bool get_type_tile(int tile_x){
    bool action = false;
    char type = game.get_map().map.at(tile_x);
    
  
         if(type == 't'){
            action = game.get_player().cut_tree(tile_x);
             
        }
        if(type == 'f'){
           action = game.get_player().fish(tile_x);
            
        }
        if(type == 'r'){
            action = game.get_player().mine_rock(tile_x);
        }
    
        if(type == '$'){
            action = game.get_player().shop(tile_x);
        }
    
        if(type == '^'){
            action = game.get_player().buy_shop(tile_x);
        }
    
   
    return action;
    
   
}

void click(int x, int y, RenderWindow & window){
    int tile_x = get_tile_click(x);
    
  
    
    Texture m_texture;
    m_texture.loadFromFile(resourcePath() + "click_marker.png");
    Texture m_null_textre;
    m_null_textre.loadFromFile(resourcePath() + "click_marker_null.png");
    

    bool success = get_type_tile(tile_x) ;
    
    Sprite mouse_sprite;

    if(success){
        mouse_sprite.setTexture(m_texture);
    }else{
        mouse_sprite.setTexture(m_null_textre);

    }
    
    

    
    mouse_sprite.setColor(Color::White);
    mouse_sprite.setPosition(x - 25, y - 25);
    mouse_sprite.setScale(5, 5);
    

    
    
    
    
    window.draw(mouse_sprite);
    
    //window.draw(click_marker);
    
}

int main(int, char const**){
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1400, 900), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    
    player_texture.loadFromFile(resourcePath() + "player_idel.png");
    
    //spr
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // Program font
    sf::Font font;
    if (!systemFont.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
   
    window.setKeyRepeatEnabled(false);
    // Start the game loop
    while (window.isOpen()){
        
        
        render(window);

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if(event.type == sf::Event::MouseButtonPressed){ // Mouse click
                click(event.mouseButton.x, event.mouseButton.y,  window);
                
              //  cout << "clicked_x: " << get_tile_click(event.mouseButton.x) << endl;
                
                
                
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed) {
                //game.spawn();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right )) {
                game.get_player().move(1);
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left )) {
                game.get_player().move(-1);
            }
            
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num1)) {
                game.get_player().get_invo().add_tool(Tool("pickaxe"));
               // cout << game.get_player().get_invo().get_tools().at(0).name << endl ;
            }
            

            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num2)) {
                game.get_player().get_invo().add_tool(Tool("axe"));
            
            }
            
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num3)) {
                game.get_player().get_invo().add_tool(Tool("fishing_pole"));
                
            }
            
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Up)) {
                game.get_player().get_invo().next_tool();
            }
            
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down)) {
                if(game.get_player().in_shop){
                    game.get_player().get_invo().next_item();
                }
               
                if(game.get_player().in_store_buying){
                    game.get_shops().next_weapon();
                    
                }
            }
            
          
            
            
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return)) {
                if(game.get_player().in_shop){
                    cout << "sell item: " << game.get_player().get_invo().cur_item.name << endl;
                    int gp_gained = game.get_player().get_invo().sell_item(game.get_player().get_invo().cur_item);
                    game.get_player().set_coins(game.get_player().get_coins() + gp_gained);
                }
                
                if(game.get_player().in_store_buying){
                    if(!game.get_player().get_invo().has_weapon(game.get_shops().cur_weapon.name)){
                        if(game.get_player().get_coins() >= game.get_shops().cur_weapon.cost){
                            game.get_player().get_invo().add_weapon(game.get_shops().cur_weapon);
                            game.get_player().set_coins(game.get_player().get_coins() - game.get_shops().cur_weapon.cost);
                            cout << "bought item!" << endl;
                        }else{
                            cout << "not enought gp" << endl;
                        }
                       
                    }else{
                        cout << "You already own this item" << endl;
                    }
               
                }
                
               
            }
            
            
          
            
        }

   
        
        
      
       
        sf:sleep(sf::seconds(0.05)); // Slows cpu from 100% to 1% :)

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
