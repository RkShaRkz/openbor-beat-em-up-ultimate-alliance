void main()
{// Animation changer with Opponent check
	void self 	= getlocalvar("self");
	void player	= getplayerproperty(3, "entity");
    void target = getentityproperty(player, "opponent");
	void iType	= getentityproperty(target, "type");

   if(target==NULL())
   {
     changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
   }else if(target!=NULL() && iType != openborconstant("TYPE_ENEMY") && iType != openborconstant("TYPE_PLAYER"))
   {
     changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
   }else if(target!=NULL() && iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_PLAYER"))
   {
     changeentityproperty(self, "animation", openborconstant("ANI_IDLE2"));
   }
}