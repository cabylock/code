const collection = require('./database');
const http = require('http');

let port = 27018;  let hostname = "127.0.0.1";
http.createServer((req, res) => 
{
      res.setHeader('access-control-allow-origin', '*');
      res.setHeader('access-control-allow-methods', 'GET, POST, PUT, DELETE');
      
      let data = '';
      req.on('data', chunk => { data += chunk; });
      req.on('end', () => 
      {
            if(req.url === '/create')
            {
                  let user = JSON.parse(data);
                  collection.findOne({name: user.name})
                  .then( users => 
                  {
                        if(users)
                        {
                              res.end('User already exists');
                        }
                        else
                        {
                              collection.create(user).then(() => res.end('User created'));
                        }
                  }
                    )
            }
            else if( req.url === '/read')
            {
                  let user = JSON.parse(data);
                  collection.findOne({name : user.name})
                  .then( users => {  
                        if(users )
                        {
                              res.end(JSON.stringify(users));
                        }
                        else 
                        {
                              res.end("User not found");
                        }
                  }     );
            }
            else if( req.url === '/update')
            {
                  let user = JSON.parse(data);
                  
                  collection.findOneAndUpdate({name : user.name}, { $set: {age : user.age ,male : user.male} }    )
                  .then(     (user)=>
                  {
                        if(user)
                        {
                              res.end('User updated');
                        }
                        else
                        {
                              res.end('User not found');
                        }
                  }
                  );
            }
            else if( req.url === '/delete')
            {
                  let user = JSON.parse(data);
                  
                  collection.deleteOne({name : user.name}).then(() => res.end('User deleted'));
            }
            else
            {
                  res.end('Invalid request');
            }        
      });

})
.listen(port, hostname, () => {   console.log(`Server running at http://${hostname}:${port}/`);  });   ;









