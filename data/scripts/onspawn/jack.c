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
	int  Add		= 200*pCount; //Each active player add more Health to him
	int  set		= openborvariant("current_set");
	
	if(set == 2 || set == 3)
	{
		changeentityproperty(self, "nodieblink", 3);
	}
	
	if(vRName == "Jack0"){
		vAlias		= "Jack";
		iMHealth	= 200+Add;
		iHealth 	= iMHealth;
		iSpeed 		= 0.8;
		iAggre 		= 500;
		iScore 		= 3000*pCount;
		iMap		= 0;
	}else if(vRName == "Jack1"){
		vAlias		= "Beano";
		iMHealth	= 300+Add;
		iHealth 	= iMHealth;
		iSpeed 		= 1;
		iAggre 		= 1000;
		iScore 		= 6000*pCount;
		iMap		= 1;
	}else if(vRName == "Jack2"){
		vAlias		= "Soya";
		iMHealth	= 400+Add;
		iHealth 	= iMHealth;
		iSpeed 		= 1.2;
		iAggre 		= 1500;
		iScore 		= 9000*pCount;
		iMap		= 2;
	}
	
	changeentityproperty(self, "name", vAlias); //Set alias.
	changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "speed", iSpeed); //Set speed.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
}