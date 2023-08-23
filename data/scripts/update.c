void main()
{
	pressStart();
	selectBack();
	selectPlayer();
	arrowSelect();
	charAxel();
	charBlaze();
	charMax();
	charSammy();
	charcaptain();
	charBaby();
	charHannah();
	charGuy();
        charMustapha();
	completeScreen();
	top10Screen();
	guardFull();
	drawKO();
	clearG();
	//drawFree();
}

void drawFree()
{// Draw Free Text
	
	//drawstring(50, 10, 1, "RUN >>");
	//drawstring(50, 30, 1, "DODGE DURING WALK OR RUN, PRESS D");
	//drawstring(50, 50, 1, "SAFE LAND HOLD > + J WHEN THROWNED");
	//drawstring(50, 70, 1, "FAST RISE HOLD > + A WHEN FALLEN");
	//drawstring(50, 90, 1, "BACK ATTACK HOLD A + PRESS J");
	//drawstring(50, 110, 1, "JUMP ATTACK DURING JUMP, HOLD < OR > + PRESS A");
	//drawstring(50, 130, 1, "RUN ATTACK DURING RUN, PRESS A");
	//drawstring(50, 150, 1, "GRAB ATTACK DURING GRAB, HOLD < OR > + PRESS A");
	//drawstring(50, 170, 1, "COUNTER ATTACK DURING BLOCK, HOLD A");
	//drawstring(50, 190, 1, "DEFENSIVE SPECIAL ATTACK PRESS S");
	//drawstring(50, 210, 1, "OFFENSIVE SPECIAL ATTACK HOLD > + PRESS S");
	//drawstring(50, 230, 1, "RAGE ATTACK PRESS R");
	//drawstring(50, 250, 1, "GRAB ENEMY MOVE CLOSE TO THE ENEMY");
	//drawstring(50, 260, 1, "TAKE ITEM/WEAPON MOVE CLOSE TO THE ITEM/WEAPON + PRESS A");
	//drawstring(210, 100, 7, "HOW");
	//drawstring(310, 100, 7, "TO");
	//drawstring(410, 100, 7, "PLAY");
	//drawstring(210, 50, 1, "BUTTONS");
	//drawstring(310, 50, 1, "COMMANDS");
	//drawstring(210, 160, 0, "ATTACK");
	//drawstring(210, 170, 0, "JUMP");
	//drawstring(210, 180, 0, "SPECIAL");
	//drawstring(210, 190, 0, "RAGE");
	//drawstring(210, 200, 0, "BLOCK");
	//drawstring(210, 210, 0, "DODGE");
	//drawstring(210, 220, 0, "MOVE");
	//drawstring(128, 100, 1, "2017");
	//drawstring(128, 110, 0, "KRATUS");
	//drawstring(128, 120, 0, "PRESS START");
	//drawstring(128, 130, 1, "VER.");
	//drawstring(128, 140, 0, "1.0");
	//drawstring(128, 100, 7, "SPECIAL THANKS");
	//drawstring(210, 120, 0, "CHRONO CRASH");
	//drawstring(212, 130, 0, "SENILE TEAM");
	//drawstring(207, 140, 0, "OPENBOR STAFF");
	//drawstring(230, 150, 0, "SEGA");
	//drawstring(210, 160, 0, "YUZO KOSHIRO");
	//drawstring(210, 160, 0, "BOMBERGAMES");
	//drawstring(210, 170, 0, "COMMANDER SOUND");
	//drawstring(210, 180, 0, "CAPCOM");
	//drawstring(210, 190, 0, "SNK");
	//drawstring(210, 160, 0, "AND YOU...");
	//drawstring(210, 160, 7, "GAME OVER");
}

void pressStart()
{// Play Press Start Webm
	
	if(openborvariant("in_titlescreen"))
	{
		playwebm("data/scenes/start.webm");
	}
	
	if(openborvariant("in_titlescreen")){
		if(playerkeys(0, 1, "start")	||
		playerkeys(0, 1, "attack")		||
		playerkeys(0, 1, "attack2")		||
		playerkeys(0, 1, "attack3")		||
		playerkeys(0, 1, "attack4")		||
		playerkeys(0, 1, "jump")		||
		playerkeys(0, 1, "special")		||
		
		playerkeys(1, 1, "start")		||
		playerkeys(1, 1, "attack")		||
		playerkeys(1, 1, "attack2")		||
		playerkeys(1, 1, "attack3")		||
		playerkeys(1, 1, "attack4")		||
		playerkeys(1, 1, "jump")		||
		playerkeys(1, 1, "special")		||
		
		playerkeys(2, 1, "start")		||
		playerkeys(2, 1, "attack")		||
		playerkeys(2, 1, "attack2")		||
		playerkeys(2, 1, "attack3")		||
		playerkeys(2, 1, "attack4")		||
		playerkeys(2, 1, "jump")		||
		playerkeys(2, 1, "special")		||
		
		playerkeys(3, 1, "start")		||
		playerkeys(3, 1, "attack")		||
		playerkeys(3, 1, "attack2")		||
		playerkeys(3, 1, "attack3")		||
		playerkeys(3, 1, "attack4")		||
		playerkeys(3, 1, "jump")		||
		playerkeys(3, 1, "special"))	{
		
			playwebm("data/scenes/blank.webm");
		} else {
			playwebm("data/scenes/intro.webm");
		}
	}
}

void selectBack()
{// Spawn Select Screen Background

	if(openborvariant("in_menuscreen"))
    {
		setlocalvar("counter",0);
    }
	
	if(openborvariant("in_selectscreen")){
		void counter = getlocalvar("counter");  // Set a variable to trigger the spawn on and off
		while(counter!=1) // Check the variable to avoid double spawn
		{
			void subent;
			clearspawnentry(); // clean the spawn entry
			setspawnentry("name", "select_back"); // define the entity to be spawn
			setspawnentry("coords", 0,0,0); // set the position of the entity
			subent=spawn();  //  spawn the entity
			changeentityproperty(subent, "position",0,0,0);//for safe, set again the position
			changeentityproperty(subent, "direction",1); //for safe, set again the position
			counter = setlocalvar("counter",1); // turn on the variable, blocking a new spawn to be made
		}
	}
}

void selectPlayer()
{// Draw Select Player Title
	
	if(openborvariant("in_selectscreen"))
	{
		drawstring(131, 2, 7, "SELECT");
		drawstring(250, 2, 7, "PLAYER");
	}
}

void arrowSelect()
{// Draw Arrow left/right/up/down to show more playable characters and collors
	
	if(openborvariant("in_selectscreen"))
	{
		drawstring(119, 128, 9, "a");
		drawstring(326, 128, 9, "b");
		drawstring(223, 23, 9, "c");
		drawstring(223, 233, 9, "d");
	}
}

void charAxel()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Axel"){
			drawstring(78, 49, 4, "1p");
			drawstring(125, 15, 9, "0");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "|||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "|||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "|||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "||");
			}
		if(vName2 == "Axel"){
			drawstring(385, 49, 3, "2p");
			drawstring(135, 15, 9, "1");
			drawstring(410, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(373, 69, 8, "|||");
			drawstring(385, 81, 8, "Life");
			drawstring(373, 81, 8, "|||");
			drawstring(385, 93, 8, "Power");
			drawstring(373, 93, 8, "|||");
			drawstring(385, 105, 8, "Speed");
			drawstring(376, 105, 8, "||");
			drawstring(385, 117, 8, "Jump");
			drawstring(376, 117, 8, "||");
			drawstring(385, 129, 8, "Special");
			drawstring(376, 129, 8, "||");
			}
		if(vName3 == "Axel"){
			drawstring(77, 181, 5, "3p");
			drawstring(145, 15, 9, "2");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "|||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "|||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "|||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "||");
			}
		if(vName4 == "Axel"){
			drawstring(385, 181, 6, "4p");
			drawstring(155, 15, 9, "3");
			drawstring(410, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(373, 201, 8, "|||");
			drawstring(385, 213, 8, "Life");
			drawstring(373, 213, 8, "|||");
			drawstring(385, 225, 8, "Power");
			drawstring(373, 225, 8, "|||");
			drawstring(385, 237, 8, "Speed");
			drawstring(376, 237, 8, "||");
			drawstring(385, 249, 8, "Jump");
			drawstring(376, 249, 8, "||");
			drawstring(385, 261, 8, "Special");
			drawstring(376, 261, 8, "||");
		}
	}
}


void charBlaze()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Blaze"){
			drawstring(78, 49, 4, "1p");
			drawstring(170, 15, 9, "4");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "||||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "|||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "|||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "|||");
			}
		if(vName2 == "Blaze"){
			drawstring(385, 49, 3, "2p");
			drawstring(180, 15, 9, "5");
			drawstring(393, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(370, 69, 8, "||||");
			drawstring(385, 81, 8, "Life");
			drawstring(376, 81, 8, "||");
			drawstring(385, 93, 8, "Power");
			drawstring(376, 93, 8, "||");
			drawstring(385, 105, 8, "Speed");
			drawstring(373, 105, 8, "|||");
			drawstring(385, 117, 8, "Jump");
			drawstring(373, 117, 8, "|||");
			drawstring(385, 129, 8, "Special");
			drawstring(373, 129, 8, "|||");
			}
		if(vName3 == "Blaze"){
			drawstring(77, 181, 5, "3p");
			drawstring(190, 15, 9, "6");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "||||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "|||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "|||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "|||");
			}
		if(vName4 == "Blaze"){
			drawstring(385, 181, 6, "4p");
			drawstring(200, 15, 9, "7");
			drawstring(393, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(370, 201, 8, "||||");
			drawstring(385, 213, 8, "Life");
			drawstring(376, 213, 8, "||");
			drawstring(385, 225, 8, "Power");
			drawstring(376, 225, 8, "||");
			drawstring(385, 237, 8, "Speed");
			drawstring(373, 237, 8, "|||");
			drawstring(385, 249, 8, "Jump");
			drawstring(373, 249, 8, "|||");
			drawstring(385, 261, 8, "Special");
			drawstring(373, 261, 8, "|||");
		}
	}
}

void charMax()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Max"){
			drawstring(78, 49, 4, "1p");
			drawstring(215, 15, 9, "4");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "||||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "||||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "|");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "|");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "|");
			}
		if(vName2 == "Max"){
			drawstring(385, 49, 3, "2p");
			drawstring(225, 15, 9, "5");
			drawstring(427, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(376, 69, 8, "||");
			drawstring(385, 81, 8, "Life");
			drawstring(370, 81, 8, "||||");
			drawstring(385, 93, 8, "Power");
			drawstring(370, 93, 8, "||||");
			drawstring(385, 105, 8, "Speed");
			drawstring(379, 105, 8, "|");
			drawstring(385, 117, 8, "Jump");
			drawstring(379, 117, 8, "|");
			drawstring(385, 129, 8, "Special");
			drawstring(379, 129, 8, "|");
			}
		if(vName3 == "Max"){
			drawstring(77, 181, 5, "3p");
			drawstring(235, 15, 9, "6");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "||||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "||||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "|");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "|");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "|");
			}
		if(vName4 == "Max"){
			drawstring(385, 181, 6, "4p");
			drawstring(245,  15, 9, "7");
			drawstring(427, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(376, 201, 8, "||");
			drawstring(385, 213, 8, "Life");
			drawstring(370, 213, 8, "||||");
			drawstring(385, 225, 8, "Power");
			drawstring(370, 225, 8, "||||");
			drawstring(385, 237, 8, "Speed");
			drawstring(379, 237, 8, "|");
			drawstring(385, 249, 8, "Jump");
			drawstring(379, 249, 8, "|");
			drawstring(385, 261, 8, "Special");
			drawstring(379, 261, 8, "|");
		}
	}
}

void charSammy()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Sammy"){
			drawstring(78, 49, 4, "1p");
			drawstring(260, 15, 9, "0");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "|");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "|");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "|");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "||||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "||||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "||||");
			}
		if(vName2 == "Sammy"){
			drawstring(385, 49, 3, "2p");
			drawstring(270, 15, 9, "1");
			drawstring(393, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(379, 69, 8, "|");
			drawstring(385, 81, 8, "Life");
			drawstring(379, 81, 8, "|");
			drawstring(385, 93, 8, "Power");
			drawstring(379, 93, 8, "|");
			drawstring(385, 105, 8, "Speed");
			drawstring(370, 105, 8, "||||");
			drawstring(385, 117, 8, "Jump");
			drawstring(370, 117, 8, "||||");
			drawstring(385, 129, 8, "Special");
			drawstring(370, 129, 8, "||||");
			}
		if(vName3 == "Sammy"){
			drawstring(77, 181, 5, "3p");
			drawstring(280, 15, 9, "2");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "|");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "|");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "|");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "||||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "||||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "||||");
			}
		if(vName4 == "Sammy"){
			drawstring(385, 181, 6, "4p");
			drawstring(290, 15, 9, "3");
			drawstring(393, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(379, 201, 8, "|");
			drawstring(385, 213, 8, "Life");
			drawstring(379, 213, 8, "|");
			drawstring(385, 225, 8, "Power");
			drawstring(379, 225, 8, "|");
			drawstring(385, 237, 8, "Speed");
			drawstring(370, 237, 8, "||||");
			drawstring(385, 249, 8, "Jump");
			drawstring(370, 249, 8, "||||");
			drawstring(385, 261, 8, "Special");
			drawstring(370, 261, 8, "||||");
		}
	}
}

void charcaptain()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "captain"){
		        drawstring(78, 49, 4, "1p");
			drawstring(125, 60, 9, "0");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "|||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "|||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "|||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "|||");
			}
		if(vName2 == "captain"){
                        drawstring(385, 49, 3, "2p");
			drawstring(135, 60, 9, "1");
			drawstring(373, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(373, 69, 8, "|||");
			drawstring(385, 81, 8, "Life");
			drawstring(373, 81, 8, "|||");
			drawstring(385, 93, 8, "Power");
			drawstring(373, 93, 8, "|||");
			drawstring(385, 105, 8, "Speed");
			drawstring(376, 105, 8, "||");
			drawstring(385, 117, 8, "Jump");
			drawstring(376, 117, 8, "||");
			drawstring(385, 129, 8, "Special");
			drawstring(376, 129, 8, "|||");
			}
		if(vName3 == "captain"){
			drawstring(77, 181, 5, "3p");
			drawstring(145, 60, 9, "2");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "|||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "|||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "|||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "|||");

			}
		if(vName4 == "captain"){
	                drawstring(385, 181, 6, "4p");
			drawstring(155, 60, 9, "3");
			drawstring(373, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(373, 201, 8, "|||");
			drawstring(385, 213, 8, "Life");
			drawstring(373, 213, 8, "|||");
			drawstring(385, 225, 8, "Power");
			drawstring(373, 225, 8, "|||");
			drawstring(385, 237, 8, "Speed");
			drawstring(376, 237, 8, "||");
			drawstring(385, 249, 8, "Jump");
			drawstring(376, 249, 8, "||");
			drawstring(385, 261, 8, "Special");
			drawstring(376, 261, 8, "|||");
		}
	}
}

void charBaby()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Baby"){
			drawstring(78, 49, 4, "1p");
			drawstring(260, 60, 9, "4");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "||||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "||||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "|");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "|");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "|");
			}
		if(vName2 == "Baby"){
			drawstring(385, 49, 3, "2p");
			drawstring(270, 60, 9, "5");
			drawstring(427, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(376, 69, 8, "||");
			drawstring(385, 81, 8, "Life");
			drawstring(370, 81, 8, "||||");
			drawstring(385, 93, 8, "Power");
			drawstring(370, 93, 8, "||||");
			drawstring(385, 105, 8, "Speed");
			drawstring(379, 105, 8, "|");
			drawstring(385, 117, 8, "Jump");
			drawstring(379, 117, 8, "|");
			drawstring(385, 129, 8, "Special");
			drawstring(379, 129, 8, "|");
			}
		if(vName3 == "Baby"){
			drawstring(77, 181, 5, "3p");
			drawstring(280, 60, 9, "6");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "||||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "||||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "|");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "|");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "|");
			}
		if(vName4 == "Baby"){
			drawstring(385, 181, 6, "4p");
			drawstring(290,  60, 9, "7");
			drawstring(427, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(376, 201, 8, "||");
			drawstring(385, 213, 8, "Life");
			drawstring(370, 213, 8, "||||");
			drawstring(385, 225, 8, "Power");
			drawstring(370, 225, 8, "||||");
			drawstring(385, 237, 8, "Speed");
			drawstring(379, 237, 8, "|");
			drawstring(385, 249, 8, "Jump");
			drawstring(379, 249, 8, "|");
			drawstring(385, 261, 8, "Special");
			drawstring(379, 261, 8, "|");
		}
	}
}


void charHannah()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Hannah"){
			drawstring(78, 49, 4, "1p");
			drawstring(170, 105, 9, "4");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "||||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "|||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "|||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "|||");
			}
		if(vName2 == "Hannah"){
			drawstring(385, 49, 3, "2p");
			drawstring(180, 105, 9, "5");
			drawstring(373, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(370, 69, 8, "||||");
			drawstring(385, 81, 8, "Life");
			drawstring(376, 81, 8, "||");
			drawstring(385, 93, 8, "Power");
			drawstring(376, 93, 8, "||");
			drawstring(385, 105, 8, "Speed");
			drawstring(373, 105, 8, "|||");
			drawstring(385, 117, 8, "Jump");
			drawstring(373, 117, 8, "|||");
			drawstring(385, 129, 8, "Special");
			drawstring(373, 129, 8, "|||");
			}
		if(vName3 == "Hannah"){
			drawstring(77, 181, 5, "3p");
			drawstring(190, 105, 9, "6");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "||||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "|||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "|||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "|||");
			}
		if(vName4 == "Hannah"){
			drawstring(385, 181, 6, "4p");
			drawstring(200, 105, 9, "7");
			drawstring(373, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(370, 201, 8, "||||");
			drawstring(385, 213, 8, "Life");
			drawstring(376, 213, 8, "||");
			drawstring(385, 225, 8, "Power");
			drawstring(376, 225, 8, "||");
			drawstring(385, 237, 8, "Speed");
			drawstring(373, 237, 8, "|||");
			drawstring(385, 249, 8, "Jump");
			drawstring(373, 249, 8, "|||");
			drawstring(385, 261, 8, "Special");
			drawstring(373, 261, 8, "|||");
		}
	}
}

void charMustapha()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Mustapha"){
			drawstring(78, 49, 4, "1p");
			drawstring(260, 105, 9, "0");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "|||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "|||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "|||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "||||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "||||");
			}
		if(vName2 == "Mustapha"){
			drawstring(385, 49, 3, "2p");
			drawstring(270, 105, 9, "1");
			drawstring(365, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(373, 69, 8, "|||");
			drawstring(385, 81, 8, "Life");
			drawstring(373, 81, 8, "|||");
			drawstring(385, 93, 8, "Power");
			drawstring(373, 93, 8, "|||");
			drawstring(385, 105, 8, "Speed");
			drawstring(376, 105, 8, "||");
			drawstring(385, 117, 8, "Jump");
			drawstring(370, 117, 8, "||||");
			drawstring(385, 129, 8, "Special");
			drawstring(370, 129, 8, "||||");
			}
		if(vName3 == "Mustapha"){
			drawstring(77, 181, 5, "3p");
			drawstring(280, 105, 9, "2");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "|||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "|||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "|||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "||||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "||||");
			}
		if(vName4 == "Mustapha"){
			drawstring(385, 181, 6, "4p");
			drawstring(290, 105, 9, "3");
			drawstring(365, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(373, 201, 8, "|||");
			drawstring(385, 213, 8, "Life");
			drawstring(373, 213, 8, "|||");
			drawstring(385, 225, 8, "Power");
			drawstring(373, 225, 8, "|||");
			drawstring(385, 237, 8, "Speed");
			drawstring(376, 237, 8, "||");
			drawstring(385, 249, 8, "Jump");
			drawstring(370, 249, 8, "||||");
			drawstring(385, 261, 8, "Special");
			drawstring(370, 261, 8, "||||");
		}
	}
}

void charGuy()
{// Draw Char Name in Select Screen
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");
	
	if(openborvariant("in_selectscreen")){
		if(vName1 == "Guy"){
			drawstring(78, 49, 4, "1p");
			drawstring(125, 150, 9, "0");
			drawstring(5, 25, 7, vName1);
			drawstring(74, 69, 8, "Skills");
			drawstring(99, 69, 8, "|||");
			drawstring(80, 81, 8, "Life");
			drawstring(99, 81, 8, "|||");
			drawstring(69, 93, 8, "Power");
			drawstring(99, 93, 8, "|||");
			drawstring(70, 105, 8, "Speed");
			drawstring(99, 105, 8, "||");
			drawstring(74, 117, 8, "Jump");
			drawstring(99, 117, 8, "||");
			drawstring(66, 129, 8, "Special");
			drawstring(99, 129, 8, "||");
			}
		if(vName2 == "Guy"){
			drawstring(385, 49, 3, "2p");
			drawstring(135, 150, 9, "1");
			drawstring(410, 25, 7, vName2);
			drawstring(385, 69, 8, "Skills");
			drawstring(373, 69, 8, "|||");
			drawstring(385, 81, 8, "Life");
			drawstring(373, 81, 8, "|||");
			drawstring(385, 93, 8, "Power");
			drawstring(373, 93, 8, "|||");
			drawstring(385, 105, 8, "Speed");
			drawstring(376, 105, 8, "||");
			drawstring(385, 117, 8, "Jump");
			drawstring(376, 117, 8, "||");
			drawstring(385, 129, 8, "Special");
			drawstring(376, 129, 8, "||");
			}
		if(vName3 == "Guy"){
			drawstring(77, 181, 5, "3p");
			drawstring(145, 150, 9, "2");
			drawstring(5, 157, 7, vName3);
			drawstring(74, 201, 8, "Skills");
			drawstring(99, 201, 8, "|||");
			drawstring(80, 213, 8, "Life");
			drawstring(99, 213, 8, "|||");
			drawstring(69, 225, 8, "Power");
			drawstring(99, 225, 8, "|||");
			drawstring(70, 237, 8, "Speed");
			drawstring(99, 237, 8, "||");
			drawstring(74, 249, 8, "Jump");
			drawstring(99, 249, 8, "||");
			drawstring(66, 261, 8, "Special");
			drawstring(99, 261, 8, "||");
			}
		if(vName4 == "Guy"){
			drawstring(385, 181, 6, "4p");
			drawstring(155, 150, 9, "3");
			drawstring(410, 157, 7, vName4);
			drawstring(385, 201, 8, "Skills");
			drawstring(373, 201, 8, "|||");
			drawstring(385, 213, 8, "Life");
			drawstring(373, 213, 8, "|||");
			drawstring(385, 225, 8, "Power");
			drawstring(373, 225, 8, "|||");
			drawstring(385, 237, 8, "Speed");
			drawstring(376, 237, 8, "||");
			drawstring(385, 249, 8, "Jump");
			drawstring(376, 249, 8, "||");
			drawstring(385, 261, 8, "Special");
			drawstring(376, 261, 8, "||");
		}
	}
}

void completeScreen()
{// Draw Title and player number in Stage Complete
	void vName1	= getplayerproperty(0, "entity");
	void vName2	= getplayerproperty(1, "entity");
	void vName3	= getplayerproperty(2, "entity");
	void vName4	= getplayerproperty(3, "entity");
	int set 	= openborvariant("current_set");
	int stage 	= openborvariant("current_stage");
	
	if(openborvariant("in_showcomplete")){
		if(set == 0){
			drawstring(108, 55, 7, "STAGE");
			drawstring(209, 55, 7, stage);
			drawstring(240, 55, 7, "COMPLETE");
			if(vName1 != NULL()){
				drawstring(182, 88, 9, "4");
				}
			if(vName2 != NULL()){
				drawstring(242, 88, 9, "5");
				}
			if(vName3 != NULL()){
				drawstring(302, 88, 9, "6");
				}
			if(vName4 != NULL()){
				drawstring(362, 88, 9, "7");
			}
		}
		
		if(set == 1){
			drawstring(108, 55, 7, "STAGE");
			drawstring(209, 55, 7, stage);
			drawstring(240, 55, 7, "COMPLETE");
			if(vName1 != NULL()){
				drawstring(182, 88, 9, "4");
				}
			if(vName2 != NULL()){
				drawstring(242, 88, 9, "5");
				}
			if(vName3 != NULL()){
				drawstring(302, 88, 9, "6");
				}
			if(vName4 != NULL()){
				drawstring(362, 88, 9, "7");
			}
		}
		
		if(set == 2){
			drawstring(102, 55, 7, "SURVIVAL");
			drawstring(245, 55, 7, "COMPLETE");
			if(vName1 != NULL()){
				drawstring(182, 88, 9, "4");
				}
			if(vName2 != NULL()){
				drawstring(242, 88, 9, "5");
				}
			if(vName3 != NULL()){
				drawstring(302, 88, 9, "6");
				}
			if(vName4 != NULL()){
				drawstring(362, 88, 9, "7");
			}
		}
		
		if(set == 3){
			drawstring(94, 55, 7, "SYNDICATE");
			drawstring(255, 55, 7, "COMPLETE");
			if(vName1 != NULL()){
				drawstring(182, 88, 9, "4");
				}
			if(vName2 != NULL()){
				drawstring(242, 88, 9, "5");
				}
			if(vName3 != NULL()){
				drawstring(302, 88, 9, "6");
				}
			if(vName4 != NULL()){
				drawstring(362, 88, 9, "7");
			}
		}
	}
}

void top10Screen()
{// Draw Title Top 10 Screen
	
	if(openborvariant("in_halloffamescreen"))
	{
		drawstring(143, 20, 7, "TOP");
		drawstring(210, 20, 7, "10");
		drawstring(255, 20, 7, "PLAYERS");
		drawstring(153, 54, 7, "RANK");
		drawstring(283, 54, 7, "SCORE");
	}
}

void guardFull()
{// Draw line with Players Guardpoints check
    void player1	= getplayerproperty(0, "entity");
	void player2	= getplayerproperty(1, "entity");
	void player3	= getplayerproperty(2, "entity");
	void player4	= getplayerproperty(3, "entity");
	int iLives1		= getplayerproperty(0, "lives");
	int iLives2		= getplayerproperty(1, "lives");
	int iLives3		= getplayerproperty(2, "lives");
	int iLives4		= getplayerproperty(3, "lives");
	int iHealth1 	= getentityproperty(player1, "health");
	int iHealth2 	= getentityproperty(player2, "health");
	int iHealth3 	= getentityproperty(player3, "health");
	int iHealth4 	= getentityproperty(player4, "health");
	float iGuard1	= getentityproperty(player1, "guardpoints");
	float iGuard2	= getentityproperty(player2, "guardpoints");
	float iGuard3	= getentityproperty(player3, "guardpoints");
	float iGuard4	= getentityproperty(player4, "guardpoints");
	
	if(openborvariant("in_level")){
		if(iLives1 >= 1 && iHealth1 >= 1){
			if(iGuard1 >= 1)
			{
				drawline(3, 30, 2+iGuard1, 30, 100000, -255);
				drawline(3, 31, 2+iGuard1, 31, 100000, -255);
				drawline(3, 32, 2+iGuard1, 32, 100000, -255);
			}
		}
		if(iLives2 >= 1 && iHealth2 >= 1){
			if(iGuard2 >= 1)
			{
				drawline(123, 30, 122+iGuard2, 30, 100000, -255);
				drawline(123, 31, 122+iGuard2, 31, 100000, -255);
				drawline(123, 32, 122+iGuard2, 32, 100000, -255);
			}
		}
		if(iLives3 >= 1 && iHealth3 >= 1){
			if(iGuard3 >= 1)
			{
				drawline(243, 30, 242+iGuard3, 30, 100000, -255);
				drawline(243, 31, 242+iGuard3, 31, 100000, -255);
				drawline(243, 32, 242+iGuard3, 32, 100000, -255);
			}
		}
		if(iLives4 >= 1 && iHealth4 >= 1){
			if(iGuard4 >= 1)
			{
				drawline(363, 30, 362+iGuard4, 30, 100000, -255);
				drawline(363, 31, 362+iGuard4, 31, 100000, -255);
				drawline(363, 32, 362+iGuard4, 32, 100000, -255);
			}
		}
	}
}

void drawKO()
{//Draw k.o. count
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	int iLives1	 = getplayerproperty(0, "lives");
	int iLives2	 = getplayerproperty(1, "lives");
	int iLives3	 = getplayerproperty(2, "lives");
	int iLives4	 = getplayerproperty(3, "lives");
	int iHealth1 = getentityproperty(player1, "health");
	int iHealth2 = getentityproperty(player2, "health");
	int iHealth3 = getentityproperty(player3, "health");
	int iHealth4 = getentityproperty(player4, "health");
	int ko1 	 = getglobalvar("ko1");
	int ko2 	 = getglobalvar("ko2");
	int ko3 	 = getglobalvar("ko3");
	int ko4 	 = getglobalvar("ko4");
	
	if(openborvariant("in_level")){
		if(iLives1 >= 1 && iHealth1 >= 1)
		{
			drawstring(11, 262, 1, "K.O.");
			drawstring(38, 262, 0, ko1);
		}
		
		if(iLives2 >= 1 && iHealth2 >= 1)
		{
			drawstring(131, 262, 1, "K.O.");
			drawstring(158, 262, 0, ko2);
		}
		
		if(iLives3 >= 1 && iHealth3 >= 1)
		{
			drawstring(299, 262, 1, "K.O.");
			drawstring(326, 262, 0, ko3);
		}
		
		if(iLives4 >= 1 && iHealth4 >= 1)
		{
			drawstring(419, 262, 1, "K.O.");
			drawstring(446, 262, 0, ko4);
		}
	}
}

void clearG()
{//Clear all global variables
	if(openborvariant("in_gameoverscreen")){
		clearglobalvar();
	}
	
	if(openborvariant("in_menuscreen")){
		clearglobalvar();
	}
}