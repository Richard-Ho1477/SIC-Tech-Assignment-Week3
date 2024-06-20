from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api/suhu', methods=['POST'])
def terima_data_suhu():
    data = request.json
    temperature = data['temperature']
    # Lakukan operasi atau simpan data ke database
    # Contoh: simpanDataSuhu(suhu)
    return jsonify({'message': 'Data suhu diterima!', 'temperature': temperature})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)