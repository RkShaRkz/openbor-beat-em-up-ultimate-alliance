void koCount()
{//COUNT ENEMY K.O. FOR EACH PLAYER
	void self 	= getlocalvar("self");
	void atk 	= getlocalvar("attacker");
	void atkP 	= getentityproperty(atk,"parent");
	int dead	= getentityproperty(self,"dead");
	int player1 = getplayerproperty(0,"entity");
	int player2 = getplayerproperty(1,"entity");
	int player3 = getplayerproperty(2,"entity");
	int player4 = getplayerproperty(3,"entity");
	int ko1 	= getglobalvar("ko1");
	int ko2 	= getglobalvar("ko2");
	int ko3 	= getglobalvar("ko3");
	int ko4 	= getglobalvar("ko4");
	
	if(dead == 1){
		if(atk == player1 || atkP == player1){
			setglobalvar("ko1",ko1+1);
		}
		
		if(atk == player2 || atkP == player2){
			setglobalvar("ko2",ko2+1);
		}
		
		if(atk == player3 || atkP == player3){
			setglobalvar("ko3",ko3+1);
		}
		
		if(atk == player4 || atkP == player4){
			setglobalvar("ko4",ko4+1);
		}
	}
}