void main()
{
	tailV();
	suicideP();
	layerUPD();
	sampleplay();
}

void tailV()
{// Change Vehelits TAIL Velocity
    void self 	= getlocalvar("self");
	void target	= getentityproperty(self, "parent");
	void vName 	= getentityproperty(self, "name");
	float TxVel	= getentityproperty(target, "xdir");
	float TzVel	= getentityproperty(target, "zdir");
	int  iSpeed;
	
	if(vName == "Tail19"){
		iSpeed = 10;
	}else if(vName == "Tail18"){
		iSpeed = 9.6;
	}else if(vName == "Tail17"){
		iSpeed = 9.2;
	}else if(vName == "Tail16"){
		iSpeed = 8.8;
	}else if(vName == "Tail15"){
		iSpeed = 8.4;
	}else if(vName == "Tail14"){
		iSpeed = 8;
	}else if(vName == "Tail13"){
		iSpeed = 7.6;
	}else if(vName == "Tail12"){
		iSpeed = 7.2;
	}else if(vName == "Tail11"){
		iSpeed = 6.8;
	}else if(vName == "Tail10"){
		iSpeed = 6.4;
	}else if(vName == "Tail9"){
		iSpeed = 6;
	}else if(vName == "Tail8"){
		iSpeed = 5.6;
	}else if(vName == "Tail7"){
		iSpeed = 5.2;
	}else if(vName == "Tail6"){
		iSpeed = 4.8;
	}else if(vName == "Tail5"){
		iSpeed = 4.4;
	}else if(vName == "Tail4"){
		iSpeed = 4;
	}else if(vName == "Tail3"){
		iSpeed = 3.6;
	}else if(vName == "Tail2"){
		iSpeed = 3.2;
	}else if(vName == "Tail1"){
		iSpeed = 2.8;
	}else if(vName == "Tail0"){
		iSpeed = 2.4;
	}
		
	changeentityproperty(self, "velocity", TxVel/iSpeed, TzVel/iSpeed, 0);
}

void suicideP()
{ // Suicide if your caller is a Parent and if are dead
	void self 		= getlocalvar("self");
	void target 	= getlocalvar("Target" + self);
	void vName 		= getentityproperty(self,"name");
	int THealth 	= getentityproperty(target, "health");
	
	if(target == NULL())
	{
		target = getentityproperty(self, "parent");
		setlocalvar("Target" + self, target);
	}
	
	if(target != NULL()){
		if(THealth <= 0)
		{
			killentity(self);
		}
	}
}

void layerUPD()
{// Update layer
    void self = getlocalvar("self");
	int layer = getentityproperty(self, "z");

    changeentityproperty(self, "setlayer", layer/5);
}

void sampleplay()
{// Play defined sample
	void self 	= getlocalvar("self");
	void vName 	= getentityproperty(self,"name");
	void sample = loadsample("data/voices/vehelits/Vehelits2.wav");
	int Frame  	= getentityproperty(self,"animpos");
	
	if(vName == "Tail0"){
		if(Frame == 0)
		{
			clearlocalvar();
			playsample(openborconstant(sample), 0, 120, 120, 100, 0);
			updateframe(self, 1);
		}
	}
}