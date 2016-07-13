
<?php
if( urldecode($_GET['auth']) !== $_SERVER['GITHUB_ROBO_CLUB_SECRET']){
	printf('Unauthorized');
	http_response_code(401);
} else {
	$payload = file_get_contents('php://input');
	$data = json_decode($payload);
	var_dump($data->ref);
	if($data->ref === 'refs/heads/master'){
		echo shell_exec("sudo -u root /usr/bin/webhook_update.sh https://github.com/robo-club-iitb/robo-club-iitb.github.io robotics-club");
		printf('OK');
		http_response_code(200);
	} else {
		printf('Not master');
		http_response_code(403);
	}
}
?>
