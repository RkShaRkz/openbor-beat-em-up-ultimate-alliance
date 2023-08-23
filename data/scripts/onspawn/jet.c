void main()
{
	void self 		= getlocalvar("self");
	void vRName 	= getentityproperty(self,"defaultname"); // Get caller's real name.
	void vAlias		= getentityproperty(self,"name"); // Get caller's alias.
	int  iMHealth 	= getentityproperty(self,"maxhealth"); // Get caller's maxhealth.
	int  iHealth 	= getentityproperty(self,"health"); // Get caller's health.
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
	
	if(vRName == "Jet0"){
		vAlias		= "Jet";
		iMHealth	= 200+Add;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 0;
	}else if(vRName == "Jet1"){
		vAlias		= "Tomcat";
		iMHealth	= 200+Add;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 1;
	}else if(vRName == "Jet2"){
		vAlias		= "Mach";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 2;
	}else if(vRName == "Jet3"){
		vAlias		= "Spitfire";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 3;
	}else if(vRName == "Jet4"){
		vAlias		= "Griphis";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 4;
	}else if(vRName == "Jet5"){
		vAlias		= "Mosquite";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 5;
	}
	
	changeentityproperty(self, "name", vAlias); //Set alias.
	changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
}