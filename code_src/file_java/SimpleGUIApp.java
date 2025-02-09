

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleGUIApp {
    public static void main(String[] args) {
        // Tạo cửa sổ chính
        JFrame frame = new JFrame("Ứng dụng GUI đơn giản");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1200, 1200);
        frame.setLayout(new FlowLayout()); // Thiết lập layout

        // Tạo trường văn bản
        JTextField textField = new JTextField(15); // 15 là kích thước của trường văn bản
        frame.getContentPane().add(textField); // Thêm trường văn bản vào cửa sổ

        // Tạo nút và thêm sự kiện click
        JButton button = new JButton("Nhấn vào đây!");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Lấy văn bản từ trường văn bản
                String inputText = textField.getText();
                JOptionPane.showMessageDialog(frame, "Bạn đã nhập: " + inputText);
            }
        });

        // Thêm nút vào cửa sổ
        frame.getContentPane().add(button);
        
        // Thiết lập cửa sổ hiển thị
        frame.setVisible(true);
    }
}
