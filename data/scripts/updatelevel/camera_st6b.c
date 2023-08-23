void main()
{//Adjust camera with XPOS check

	if(openborvariant("xpos") >= 200){
		changelevelproperty("camerazoffset", 0);
	}
}