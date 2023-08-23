void main()
{//Change model with defined condition in specific set/stage/level 
 //(DUST TO SPLASH/CROWD)
    void self 	= getlocalvar("self");
	int set		= openborvariant("current_set");
	int stage 	= openborvariant("current_stage");
	int level 	= openborvariant("current_level");
	
	if(set == 0){
		if(stage == 1){
			if(level == 2){
			changeentityproperty(self, "model", "splash", 1);
			}
		}
		
		if(stage == 4){
			if(level == 16){
			changeentityproperty(self, "model", "crowd", 1);
			}
		}
	}
	
	if(set == 1){
		if(stage == 1){
			if(level == 2){
			changeentityproperty(self, "model", "splash", 1);
			}
		}
		
		if(stage == 4){
			if(level == 16){
			changeentityproperty(self, "model", "crowd", 1);
			}
		}
	}
	
	if(set == 2){
		if(stage == 1){
			if(level == 0){
			changeentityproperty(self, "model", "crowd", 1);
			}
		}
	}
	
	if(set == 3){
		if(stage == 1){
			if(level == 0){
			changeentityproperty(self, "model", "splash", 1);
			}
		}
	}
}