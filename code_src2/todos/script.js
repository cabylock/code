
let list= return_todo();
function return_todo()
{
      let todo = localStorage.getItem("todo");
      if(todo)
      {
            return JSON.parse(todo);
      }
      else
      {
            return [];
      }

}

function delete_list(value)
{
       list = return_todo();
      let index = list.findIndex((item) => item.value === value.value);
    
      list.splice(index, 1);
      localStorage.setItem("todo", JSON.stringify(list));
}

function add_li(value, checked,flag = 1)
{       
      
      
      var ul = document.getElementById("list"); // lấy thẻ ul
      
      var li = document.createElement("li"); // tạo thẻ li
      var checkbox = document.createElement("input"); // tạo thẻ input
      checkbox.type = "checkbox"; // tạo checkbox
      checkbox.id = "checkbox"; // gán id cho thẻ input
      
      var span = document.createElement("span"); // tạo thẻ span
      
      span.textContent = value; // gán value vào thẻ span
      const account =
      {
            value: value,
            checked: checked
      }
      
      if( flag) // flag = 1 thì thêm vào list // flag =0 thì là update từ local storage
     { 
      list.push(account);
      }
      localStorage.setItem("todo", JSON.stringify(list));

      var deleteButton = document.createElement("button"); // tạo thẻ button
      deleteButton.textContent = "Delete"; // gán value vào thẻ button
      deleteButton.className = "delete"; // gán id cho th
    
        checkbox.onclick = function() { li.style.textDecoration = checkbox.checked ? "line-through" : "none" 
            account.checked = checkbox.checked;
            localStorage.setItem("todo", JSON.stringify(list)); // cập nhật trạng thái checked vào local storage
        } // tạo sự kiện khi click vào checkbox
           
        span.onclick = function() { span.contentEditable = "true" 
                  account.value = span.textContent;
            } // tạo sự kiện khi click vào span
            
            localStorage.setItem("todo", JSON.stringify(list)); // cập nhật value vào local storage

        deleteButton.onclick = function() { li.remove(); delete_list(account)}// tạo sự kiện khi click vào button
        ul.appendChild(li); // thêm thẻ li vào thẻ ul
        li.appendChild(checkbox); // thêm thẻ input vào thẻ ul
        li.appendChild(span); // thêm thẻ span vào thẻ li
      li.appendChild(deleteButton); // thêm thẻ button vào thẻ ul
      document.getElementById("input").value="" 


}


function press_enter(event) 
{     
      let value = document.getElementById("input").value;
   if(event.key === 'Enter')
   {  if(value )
      add_li(value, false);
   }
}

function addTodo() 
{     let value = document.getElementById("input").value;
      if (value)
      add_li(value, false);
}

window.onload = function()
{
      let list = return_todo();
      console.log(list);
      for(let i = 0; i < list.length; i++)
      {
            add_li(list[i].value, list[i].checked,0);
      }
}





