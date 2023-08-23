void main()
{//Slow opponent xDir if hit
    void self 		= getlocalvar("self");
	void target 	= getentityproperty(self,"opponent");
	void vAniID		= getentityproperty(self,"animationID");
	int Frame		= getentityproperty(self,"animpos");
	int Ty 			= getentityproperty(target,"y");
	int tHealth		= getentityproperty(target,"health");
	float xVel 		= getentityproperty(target,"xdir");
	
	if(vAniID == openborconstant("ANI_FREESPECIAL6")){
		if(Frame <= 11){
			if(tHealth >= 1){
				changeentityproperty(target, "velocity", xVel/6, 0, 0);
			}
		}
	}
	
	if(vAniID == openborconstant("ANI_FREESPECIAL6")){
		if(Ty <= 2){
			if(Frame <= 11){
				if(tHealth >= 1){
					setidle(target);
					executeanimation(target, openborconstant("ANI_PAIN"), 1);
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"nograb",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"takeaction", "common_attack_proc");
				}
			}
		}
	}
}