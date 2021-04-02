TotalNumber()
{
			
	web_reg_save_param_ex(
    	"ParamName=NumberOfTickets", 
    	"LB/IC=<b>A total of ", 	
    	"RB/IC= scheduled flight",								
    	"Ordinal=1",
	LAST);
	
	web_url("Itinerary Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message("Total Number of tickets= %d",atoi(lr_eval_string("{NumberOfTickets}")));
	
	return 0;
}
