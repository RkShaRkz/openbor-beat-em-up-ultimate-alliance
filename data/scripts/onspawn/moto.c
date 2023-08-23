void main()
{
	void self 		= getlocalvar("self");
	void vRName 	= getentityproperty(self,"defaultname"); // Get caller's real name.
	void vAlias		= getentityproperty(self,"name"); // Get caller's alias.
	int  iMHealth 	= getentityproperty(self,"maxhealth"); // Get caller's maxhealth.
	int  iHealth 	= getentityproperty(self,"health"); // Get caller's health.
	int  iSpeed 	= getentityproperty(self,"speed"); // Get caller's speed.
	int  iAggre 	= getentityproperty(self,"aggression"); // Get caller's aggression.
	int  iScore 	= getentityproperty(self,"score"); // Get caller's score.
	int  iMap 		= getentityproperty(self,"map"); // Get caller's map.
	
	if(vRName == "Moto0"){
		vAlias		= "Fog";
		iMHealth	= 50;
		iHealth 	= iMHealth;
		iSpeed 		= 2.2;
		iAggre 		= -400;
		iScore 		= 150;
		iMap		= 0;
	}else if(vRName == "Moto1"){
		vAlias		= "Frost";
		iMHealth	= 100;
		iHealth 	= iMHealth;
		iSpeed 		= 2.4;
		iAggre 		= -200;
		iScore 		= 300;
		iMap		= 1;
	}else if(vRName == "Moto2"){
		vAlias		= "Calm";
		iMHealth	= 150;
		iHealth 	= iMHealth;
		iSpeed 		= 2.6;
		iAggre 		= 1;
		iScore 		= 450;
		iMap		= 2;
	}else if(vRName == "Moto3"){
		vAlias		= "Typhoon";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iSpeed 		= 2.8;
		iAggre 		= 200;
		iScore 		= 600;
		iMap		= 3;
	}else if(vRName == "Moto4"){
		vAlias		= "Tornado";
		iMHealth	= 250;
		iHealth 	= iMHealth;
		iSpeed 		= 3;
		iAggre 		= 400;
		iScore 		= 750;
		iMap		= 4;
	}
	
	changeentityproperty(self, "name", vAlias); //Set alias.
	changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "speed", iSpeed); //Set speed.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
}