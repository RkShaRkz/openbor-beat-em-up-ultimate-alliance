void main()
{
	JetX();
}

void JetX()
{//Spawn Enemy according player count
	int  set 	= openborvariant("current_set");
	int  stage 	= openborvariant("current_stage");
	int  pCount = openborvariant("count_players");
	
	if(set == 0){
		if(stage == 5){
			if(pCount == 1){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
			}else if(pCount == 2){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
				EnemyX("Jet5", 50, 0, 50, 1);
			}
		}else if(stage == 6){
			if(pCount == 1){
				EnemyX("Jet3", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 2){
				EnemyX("Jet3", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
				EnemyX("Jet5", 50, 0, 50, 1);
			}
		}else if(stage == 7){
			if(pCount == 1){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 2){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
				EnemyX("Jet3", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
				EnemyX("Jet3", 0, 0, 50, 0);
				EnemyX("Jet2", 50, 0, 50, 1);
			}
		}
	}
	
	if(set == 1){
		if(stage == 5){
			if(pCount == 1){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
			}else if(pCount == 2){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
				EnemyX("Jet5", 50, 0, 50, 1);
			}
		}else if(stage == 6){
			if(pCount == 1){
				EnemyX("Jet3", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 2){
				EnemyX("Jet3", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
				EnemyX("Jet5", 50, 0, 50, 1);
			}
		}else if(stage == 7){
			if(pCount == 1){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 2){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
				EnemyX("Jet3", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet5", 0, 0, 0, 0);
				EnemyX("Jet4", 50, 0, 0, 1);
				EnemyX("Jet3", 0, 0, 50, 0);
				EnemyX("Jet2", 50, 0, 50, 1);
			}
		}
	}
	
	if(set == 2){
		if(stage == 1){
			if(pCount == 1){
				EnemyX("Jet2", 0, 0, 0, 0);
			}else if(pCount == 2){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
				EnemyX("Jet5", 50, 0, 50, 1);
			}
		}
	}
	
	if(set == 3){
		if(stage == 1){
			if(pCount == 1){
				EnemyX("Jet2", 0, 0, 0, 0);
			}else if(pCount == 2){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
			}else if(pCount == 3){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
			}else if(pCount == 4){
				EnemyX("Jet2", 0, 0, 0, 0);
				EnemyX("Jet3", 50, 0, 0, 1);
				EnemyX("Jet4", 0, 0, 50, 0);
				EnemyX("Jet5", 50, 0, 50, 1);
			}
		}
	}
}

void EnemyX(void vRName, float dx, float dy, float dz, int iDir)
{	//Spawns random enemy next to caller.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
	//fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; 	//Spawn object.

	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vRName); //Acquire spawn entity by name.

	vSpawn = spawn();

	bindentity(vSpawn, self, dx, dz, dy, iDir);

	return vSpawn; //Return spawn.
}