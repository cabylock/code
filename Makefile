# in window: cd to mounted local path -> run : fsutil.exe file setCaseSensitiveInfo ./ enable
sql: 
	docker run --name mysql -e MYSQL_ROOT_PASSWORD=duong1234 \
	 -e MYSQL_ROOT_HOST=% \
        -v /media/cabylock/File/sql:/var/lib/mysql \
           --network host  -p 3306:3306  \
	  -d mysql/mysql-server


mongo: 	
	sudo chmod -R 777 /media/cabylock/File/mongo && docker run --name mongodb  \
       -v /media/cabylock/File/mongo:/data/db \
       -p 27017:27017   -d  mongodb/mongodb-community-server

end-mongodb: 
	docker stop mongodb && docker rm mongodb
	
end-sql: 
	docker stop mysql && docker rm mysql 
