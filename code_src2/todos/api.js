const http = require('http');
const collection = require('./databse');


let port =27018;
let hostname = 'localhost';


http.createServer((req, res) => 
{        
      res.setHeader('Access-Control-Allow-Origin', '*');
      res.setHeader('Access-Control-Allow-Methods', 'POST, GET, OPTIONS');


      if(req.url == '/get')
      {
            collection.find()
            .then( (data) => res.end(JSON.stringify(data)) )
            
      }
      else if( req.url == '/add')
      {
         let data ='';
         req.on('data', (chunk) => data += chunk);
         req.on('end', () => 
         {
               
               let obj = JSON.parse(data);
              
              
                        collection.insertMany([obj])
                        .then( () => res.end(1) )
                 
                        res.end(0);
                  
               
              
         }
         )
      }
      else if( req.url == '/edit')
      {
         let data ='';
         req.on('data', (chunk) => data += chunk);
         req.on('end', () => 
         {
               let obj = JSON.parse(data);
               
               collection.updateOne({value: obj.value}, {$set : {value : obj.new_value ,checked : obj.checked }})
               .then( () => res.end('Data updated successfully...') )
               
         }
          )
       }
      else if( req.url == '/delete')
      {
            let data ='';
            req.on('data', (chunk) => data += chunk);
            req.on('end', () => 
            {
                  let obj = JSON.parse(data);
                  collection.deleteOne({value : obj.value})
                  .then( () => res.end('Data deleted successfully...') )
            }
         )

      }
      else
      {
            res.end('Invalid Request...');
      }
}
)
.listen( port,hostname, () => console.log('Server is running on port 27018...'));




