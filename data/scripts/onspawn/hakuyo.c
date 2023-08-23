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
	
	if(vRName == "Hakuyo0"){
		vAlias		= "Hakuyo";
		iMHealth	= 125;
		iHealth 	= iMHealth;
		iSpeed 		= 0.8;
		iAggre 		= -400;
		iScore 		= 500*pCount;
		iMap		= 0;
	}else if(vRName == "Hakuyo_Wait0"){
		vAlias		= "Hakuyo";
		iMHealth	= 125;
		iHealth 	= iMHealth;
		iSpeed 		= 0.8;
		iAggre 		= -400;
		iScore 		= 500*pCount;
		iMap		= 0;
	}else if(vRName == "Hakuyo1"){
		vAlias		= "Suzaku";
		iMHealth	= 200;
		iHealth 	= iMHealth;
		iSpeed 		= 1;
		iAggre 		= -200;
		iScore 		= 1000*pCount;
		iMap		= 1;
	}else if(vRName == "Hakuyo2"){
		vAlias		= "Byatcko";
		iMHealth	= 300;
		iHealth 	= iMHealth;
		iSpeed 		= 1.2;
		iAggre 		= 1;
		iScore 		= 1500*pCount;
		iMap		= 2;
	}else if(vRName == "Hakuyo_Wait2"){
		vAlias		= "Byatcko";
		iMHealth	= 300;
		iHealth 	= iMHealth;
		iSpeed 		= 1.2;
		iAggre 		= 1;
		iScore 		= 1500*pCount;
		iMap		= 2;
	}else if(vRName == "Hakuyo3"){
		vAlias		= "Suicho";
		iMHealth	= 400;
		iHealth 	= iMHealth;
		iSpeed 		= 1.4;
		iAggre 		= 200;
		iScore 		= 2000*pCount;
		iMap		= 3;
	}else if(vRName == "Hakuyo4"){
		vAlias		= "Seiryu";
		iMHealth	= 500;
		iHealth 	= iMHealth;
		iSpeed 		= 1.6;
		iAggre 		= 400;
		iScore 		= 2500*pCount;
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