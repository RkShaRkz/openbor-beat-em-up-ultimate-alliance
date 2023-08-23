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
	
	if(vRName == "BigBen0"){
		vAlias		= "Big-Ben";
		iMHealth	= 300;
		iHealth 	= iMHealth;
		iSpeed 		= 0.8;
		iAggre 		= -400;
		iScore 		= 2000*pCount;
		iMap		= 0;
	}else if(vRName == "BigBen1"){
		vAlias		= "Balloon";
		iMHealth	= 450;
		iHealth 	= iMHealth;
		iSpeed 		= 1;
		iAggre 		= -200;
		iScore 		= 4000*pCount;
		iMap		= 1;
	}else if(vRName == "BigBen2"){
		vAlias		= "Heart";
		iMHealth	= 600;
		iHealth 	= iMHealth;
		iSpeed 		= 1.2;
		iAggre 		= 1;
		iScore 		= 6000*pCount;
		iMap		= 2;
	}else if(vRName == "BigBen3"){
		vAlias		= "Buffet";
		iMHealth	= 750;
		iHealth 	= iMHealth;
		iSpeed 		= 1.4;
		iAggre 		= 200;
		iScore 		= 8000*pCount;
		iMap		= 3;
	}else if(vRName == "BigBen4"){
		vAlias		= "Anry";
		iMHealth	= 900;
		iHealth 	= iMHealth;
		iSpeed 		= 1.6;
		iAggre 		= 400;
		iScore 		= 10000*pCount;
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