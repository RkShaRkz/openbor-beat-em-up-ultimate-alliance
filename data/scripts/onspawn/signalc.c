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
	int  pCount		= openborvariant("count_players"); // Count players alive.
	int  set		= openborvariant("current_set");
	
	if(set == 2 || set == 3)
	{
		changeentityproperty(self, "nodieblink", 3);
	}
	
	if(vRName == "Signal0"){
		vAlias		= "Y._Signal";
		iMHealth	= 75;
		iHealth 	= iMHealth;
		iSpeed 		= 0.8;
		iAggre 		= -400;
		iScore 		= 300*pCount;
		iMap		= 0;
	}else if(vRName == "Signal_Wait0"){
		vAlias		= "Y._Signal";
		iMHealth	= 75;
		iHealth 	= iMHealth;
		iSpeed 		= 0.8;
		iAggre 		= -400;
		iScore 		= 300*pCount;
		iMap		= 0;
	}else if(vRName == "Signal1"){
		vAlias		= "R._Signal";
		iMHealth	= 100;
		iHealth 	= iMHealth;
		iSpeed 		= 1;
		iAggre 		= -200;
		iScore 		= 600*pCount;
		iMap		= 1;
	}else if(vRName == "Signal_Gate"){
		vAlias		= "R._Signal";
		iMHealth	= 100;
		iHealth 	= iMHealth;
		iSpeed 		= 1;
		iAggre 		= -200;
		iScore 		= 600*pCount;
		iMap		= 1;	
	}else if(vRName == "Signal2"){
		vAlias		= "G._Signal";
		iMHealth	= 150;
		iHealth 	= iMHealth;
		iSpeed 		= 1.2;
		iAggre 		= 1;
		iScore 		= 900*pCount;
		iMap		= 2;
	}else if(vRName == "Signal_Wait2"){
		vAlias		= "G._Signal";
		iMHealth	= 150;
		iHealth 	= iMHealth;
		iSpeed 		= 1.2;
		iAggre 		= 1;
		iScore 		= 900*pCount;
		iMap		= 2;
	}else if(vRName == "Signal3"){
		vAlias		= "P._Signal";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iSpeed 		= 1.4;
		iAggre 		= 200;
		iScore 		= 1200*pCount;
		iMap		= 3;
	}else if(vRName == "SignalC"){
		vAlias		= "C._Signal";
		iMHealth	= 250;
		iHealth 	= iMHealth;
		iSpeed 		= 1.6;
		iAggre 		= 400;
		iScore 		= 1500*pCount;
		iMap		= 6;
	}else if(vRName == "Signal_Bottle"){
		vAlias		= "Marvin";
		iMHealth	= 300;
		iHealth 	= iMHealth;
		iSpeed 		= 1.4;
		iAggre 		= 200;
		iScore 		= 1800*pCount;
		iMap		= 5;
	}
	
	changeentityproperty(self, "name", vAlias); //Set alias.
	changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "speed", iSpeed); //Set speed.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
}