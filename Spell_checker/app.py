from flask import Flask, request, jsonify
from flask_cors import CORS  # Import CORS
import subprocess
app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

@app.route('/spellcheck', methods=['POST'])
def spellcheck():
    input_text = request.json.get('text', '')
    
    # Run the C++ executable and pass the input text
    process = subprocess.Popen(['./spellchecker'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    output, error = process.communicate(input=input_text)
    
    if error:
        return jsonify({'error': error}), 500
    
    # Return the corrected sentence
    return jsonify({'corrected_sentence': output.strip()})

if __name__ == '__main__':
    app.run(debug=True)
